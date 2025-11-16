#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "../include/io.h"
#include "../include/terminal.h"


int main() {
    struct ui_t *ui;
    for (;;) {
        ui = get_ui();
        input_processing(ui->list_ui, &ui->len_list);

        free(ui);
    }



    return EXIT_SUCCESS;
}

