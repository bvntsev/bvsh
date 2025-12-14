#include "../include/calculate.h"
#include <stdlib.h>


// 123**2
// 8123*(123+123)
// 123213+(12312**2 + 32^123 + 1&2)**2
// sqrt(2) - ?
// 123+123**(2+23**2)
// (4*23 + 123^(123*123)) + 1
//   3   4    2    1      5
// Logic: First i try to find the brackets, later i find most priority for 
// operations (like a compare between + and *)
// maybe i need put score for expression ?
// array char pointer to beginning expression in numeric?
//
char ***
evaluate_priority_expression(char **expr, uint64_t *stack_operations_n) {
    char ***priority_expr = 
        (char ***) malloc(sizeof(char **) * *stack_operations_n);
    
    return priority_expr;
}

static char check_correct_expr(const char *expr, uint64_t *len) {
    
    for (int iter = 0; iter < *len; ++iter) {

    }

    return 0;
}

struct calc *parsing_str(const char *expr, uint64_t *len) {

    if (check_correct_expr(expr, len))
        return NULL;
    struct calc *calc  = (struct calc *)malloc(sizeof(struct calc *));
    calc->stack_operations_n = 0;
    calc->stack_brackets_n = 1;
    calc->value = 0;
    
    for (uint32_t iter = 0; iter < *len; ++iter) {
        switch (expr[iter]) {
            case '+': { ++calc->stack_operations_n; break; }
            case '-': { ++calc->stack_operations_n; break; }
            case '/': { ++calc->stack_operations_n; break; }
            case '*': { ++calc->stack_operations_n; break; }
            case '^': { ++calc->stack_operations_n; break; }
            case '|': { ++calc->stack_operations_n; break; }
            case '&': { ++calc->stack_operations_n; break; }
            case '(': { ++calc->stack_brackets_n; break; }
            default: { continue; }
        }
    }
    
    for (;calc->stack_brackets_n > 0;) {
        for (uint32_t iter = 0; iter < *len; ++iter) {

        }
    }
}
