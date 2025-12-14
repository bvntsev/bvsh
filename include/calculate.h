#ifndef CALCULATE
#define CALCULATE

#include <stdint.h>

struct calc{
    char ***stack_brackets;
    uint64_t stack_brackets_n;
    char ***stack_operations;
    uint64_t stack_operations_n;
    const char *user_str;
    uint64_t value;
};



#endif // !CALCULATE
