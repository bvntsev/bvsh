#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

#include "../include/tools.h"
#include "../include/io.h"
#include "../include/terminal.h"

char *calc_verify_expr(struct ui_t *ui) { }

extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) __wur __nonnull ((3));


void print_error(enum err_t type) {

}

static void printf_ui_list(const struct ui_t *ui) {
    for (uint32_t iter = 0; iter < ui->len_list; ++iter) {
        printf("[%d] %s\n", iter, ui->list_ui[iter]);
    }
}

static void rm_void_el(struct ui_t *ui) { // FIX: need to write this with 1 loop
    // printf("%s\n", "========RM_VOID_EL=========");

    int32_t cnt_nonvoid_el = 0;
    for (uint32_t iter = 0; iter < ui->len_list; ++iter) {
        if (strncmp(ui->list_ui[iter], "", 1) != 0) {
            ++cnt_nonvoid_el;
        }
    }
    // printf("%d\n", cnt_nonvoid_el);

    char **n_list_ui = (char **)malloc(sizeof(char *) * cnt_nonvoid_el);
    uint32_t iter_list = 0;

    int32_t buffer = cnt_nonvoid_el;//FIX: Don't use the buffer for count
    
    for (uint32_t iter = 0; iter < ui->len_list ; iter++) {
        if (strncmp(ui->list_ui[iter], "", 1) != 0) {
                n_list_ui[iter_list++] = ui->list_ui[iter];
                if (cnt_nonvoid_el < 0) break;
                --cnt_nonvoid_el;
                }
        else
            free(ui->list_ui[iter]);
    }

    free(ui->list_ui);
    ui->len_list = buffer;
    ui->list_ui = n_list_ui;
}

struct ui_t *get_ui() {

    printf("\rbvsh > ");

    char *ui = NULL; // user_input
    size_t len_ui = 0;

    ssize_t r_bytes = getline(&ui, &len_ui, stdin);

    if ( r_bytes == -1 ) {
        perror("The user input get incorrect bytes\n");
    }

    ui[r_bytes-- -1] = '\0';

    if (r_bytes > 2097152) {
        perror("The argument is too long\n");
    }

    struct ui_t *ui_processed = split_ui(ui, &r_bytes, ' ');

    // printf("split_ui is good\n");

    rm_void_el(ui_processed);

    // printf_ui_list(ui_processed);
    // printf("rm_void_el is good\n");

    return ui_processed;
}


void ret_uo(char *ret_str) {
    printf("%s\n", ret_str);

}


struct ui_t *split_ui(char *ui, ssize_t *len_ui, char symbol) {

    // printf("========SPLIT_UI=========\n");

    ssize_t symb_amount = 0;
    ssize_t max_iw_len = 0, buf_iw_len = 0;

    struct ui_t *ui_split_proc = (struct ui_t *) malloc(sizeof(struct ui_t *));
    
    for (ssize_t iter = 0; iter < *len_ui; ++iter ) {
        if (ui[iter] == symbol) {
            ++symb_amount;
            if ( max_iw_len < buf_iw_len ) max_iw_len = buf_iw_len;
            buf_iw_len = 0;
        }
        else {
            buf_iw_len++;
        }
    }


#define SIZE_LIST_UI symb_amount + 1

    ui_split_proc->list_ui = (char **) malloc(sizeof(char *) * SIZE_LIST_UI);
    ui_split_proc->len_list = SIZE_LIST_UI;

    u16 list_num = 0;
    ssize_t buf_num = 0;

    char *buffer = (char *) malloc(sizeof(char) * max_iw_len + 1);

    for (ssize_t iter = 0; iter <= *len_ui; ++iter ) {
        if (ui[iter] == symbol) {
            buffer[++buf_num] = '\0';
            ui_split_proc->list_ui[list_num++] = buffer;
            buffer = (char *) malloc(sizeof(char) * max_iw_len + 1);
            buf_num = 0;
        }
        else if (iter == *len_ui) {
            buffer[++buf_num] = '\0';
            ui_split_proc->list_ui[list_num++] = buffer;
            break;
        }
        else {
            buffer[buf_num++] = ui[iter];
        }
    }

    return ui_split_proc;
}
