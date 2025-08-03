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

char *get_ui() {

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

    char **list_ui = split_ui(ui, &r_bytes, ' ');
    printf("%s\n", list_ui[0]);
    ssize_t len_list_ui = atoll(list_ui[0]);

    printf("split_ui is good\n");

    for (ssize_t i = 0; i < len_list_ui; ++i)
        printf("%s\n", list_ui[i]);
    
    return ui;
}


void ret_uo(char *ret_str) {
    printf("%s\n", ret_str);

}
