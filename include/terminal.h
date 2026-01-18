#ifndef TERMINAL_H

#define TERMINAL_H

#include "tools.h"
#include <stdint.h>

void user_cd(char **path);


int input_processing(char **input, uint32_t *len);


#endif // !TERMINAL_H
