#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/terminal.h"
#include "../include/tools.h"

char **split_ui(char *ui, ssize_t *len_ui, char symbol) {

    ssize_t symb_amount = 0;
    ssize_t max_iw_len = 0, buf_iw_len = 0;
    char **list_ui;
    
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
    char dec_to_str[10];
    sprintf(dec_to_str, "%zu", symb_amount+1);

    list_ui = (char **) malloc(sizeof(char *) * symb_amount + 2);
    list_ui[0] = dec_to_str;
    
    u16 list_num = 1;
    ssize_t buf_num = 0;

    char *buffer = (char *) malloc(sizeof(char) * max_iw_len+1);
    for (ssize_t iter = 0; iter < *len_ui; ++iter ) {
        if (ui[iter] == symbol) {
            buffer[++buf_num] = '\0';
            list_ui[list_num++] = buffer;
            buffer = (char *) malloc(sizeof(char) * max_iw_len);
            buf_num = 0;
        }
        else {
            buffer[buf_num++] = ui[iter];
        }
    }

    return list_ui;
}
