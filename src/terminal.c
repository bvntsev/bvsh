#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/terminal.h"
#include "../include/tools.h"

struct ui_t *split_ui(char *ui, ssize_t *len_ui, char symbol) {

    printf("========SPLIT_UI=========\n");

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
