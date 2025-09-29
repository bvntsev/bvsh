#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

#include "../include/io.h"
#include "../include/terminal.h"

extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) __wur __nonnull ((3));

static void printf_ui(const struct ui_t *ui) {
    for (uint32_t iter = 0; iter < ui->len_list; ++iter) {
        if (strcmp(ui->list_ui[iter], "\0") != 0) {
            printf("[%d] %s\n", iter, ui->list_ui[iter]);
        }
    }
}

static void rm_void_el(struct ui_t *ui) {
    printf("========RM_VOID_EL=========\n");

    int32_t cnt_nonvoid_el = 0;
    for (uint32_t iter = 0; iter < ui->len_list; ++iter) {
        if (strncmp(ui->list_ui[iter], " \0", 1) != 0) {
            ++cnt_nonvoid_el;
        }
    }
    printf("\n%d\n", cnt_nonvoid_el);

    char **n_list_ui = (char **)malloc(sizeof(char *) * cnt_nonvoid_el);
    uint32_t iter_list = 0;

    ui->len_list = cnt_nonvoid_el;

    for (uint32_t iter = 0; iter < ui->len_list ; iter++) {
        if (strcmp(ui->list_ui[iter], "\0" ) != 0) {
                n_list_ui[iter_list++] = ui->list_ui[iter];
                if (cnt_nonvoid_el < 0) break;
                --cnt_nonvoid_el;
                }
    }
    free(ui->list_ui);
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

    printf("split_ui is good\n");

    rm_void_el(ui_processed);

    printf_ui(ui_processed);
    printf("rm_void_el is good\n");

    return ui_processed;
}


void ret_uo(char *ret_str) {
    printf("%s\n", ret_str);

}
