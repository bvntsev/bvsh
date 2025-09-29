#ifndef TERMINAL_H

#define TERMINAL_H

#include <sys/types.h>
#include <stdint.h>

struct ui_t {
    uint32_t    len_list;
    char**      list_ui;
};

struct ui_t *split_ui(char *ui, ssize_t *len_ui, char symbol);

#endif // !TERMINAL_H
