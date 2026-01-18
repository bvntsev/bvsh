#ifndef IO_H

#define IO_H

struct ui_t *get_ui();

#include <sys/types.h>
#include <stdint.h>

char *calc_verify_expr(struct ui_t *ui);

enum err_t{warning, critical, advice};

struct ui_t {
    uint32_t    len_list;
    char**      list_ui;
};

struct ui_t *split_ui(char *ui, ssize_t *len_ui, char symbol);

void ret_uo(char *);


#endif // !IO_H
