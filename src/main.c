#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "../include/io.h"
#include "../include/terminal.h"
#include "../include/calculate.h"

extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) __wur __nonnull ((3));

int main() {
    struct ui_t *ui;
    for (;;) {

        char *ui = NULL; // user_input
        size_t len_ui = 0;

        ssize_t r_bytes = getline(&ui, &len_ui, stdin);
    
        parsing_str(ui, &len_ui);


        // ui = get_ui();
        // input_processing(ui->list_ui, &ui->len_list);
        free(ui);
    }



    return EXIT_SUCCESS;
}

