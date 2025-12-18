#include "../include/calculate.h"
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>


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

static uint64_t *check_correct_expr(const char *expr, uint64_t *len) {
    uint64_t *temp_data = malloc(sizeof(uint64_t) * 3);
    char expr_code = 0;
    uint64_t error_position = -1;
    for (uint64_t iter = 0; iter < *len-1; ++iter) {
        switch (expr[iter]){
            case '0': break;
            case '1': break;
            case '2': break;
            case '3': break;
            case '4': break;
            case '5': break;
            case '6': break;
            case '7': break;
            case '8': break;
            case '9': break;
            case '/':{
                VERIFY_MATH_OPERATOR_DIV break;
            }
            case '*':{
                VERIFY_MATH_OPERATOR break;
            }
            case '^': {
                VERIFY_MATH_OPERATOR break;
            }
            case '+': {
                VERIFY_MATH_OPERATOR break;
            }
            case '-': {
                VERIFY_MATH_OPERATOR break;
            }
            case '&': {
                VERIFY_MATH_OPERATOR break;
            }
            case '(': {
                temp_data[2]++;
                break;
            }
            case ')': {
                temp_data[2]++;
                break;
            }
            case '|': {
                VERIFY_MATH_OPERATOR break;
            }
            defaut:
                temp_data[0] = ERROR_UNKOWN_SYMBOL;
                error_position = iter;
                break;
        }
        if (expr_code != 0) break;
    } // FIX: DO NOT READ LAST CHARACTER ( extra void element at the end )
    if (expr_code == 0 && temp_data[2] % 2 != 0) {
         expr_code = ERROR_SINGLE_BRACKET;
    }
    switch (expr_code){
        case ERROR_INVALID_SYMBOL_PLACE:
            printf("ERROR: Invalid symbol place at %ld\n", error_position);
            temp_data[0] = ERROR_INVALID_SYMBOL_PLACE;
            break;
        case ERROR_UNKOWN_SYMBOL:
            printf("ERROR: Unkown symbol at %ld\n", error_position);
            temp_data[0] = ERROR_UNKOWN_SYMBOL;
            break;
        case ERROR_DIVISION_BY_ZERO:
            printf("ERROR: Division by zero at %ld\n", error_position);
            temp_data[0] = ERROR_DIVISION_BY_ZERO;
            break;
        case ERROR_SINGLE_BRACKET:
            printf("ERROR: Single bracket\n");
            temp_data[0] = ERROR_SINGLE_BRACKET;
            break;
        case ERROR_NUMBER_STARTS_AT_ZERO:
            printf("ERROR: Invalid number at %ld\n", error_position);
            temp_data[0] = ERROR_NUMBER_STARTS_AT_ZERO;
            break;
        case ERROR_DOUBLE_OPERATOR:
            printf("ERROR: Double operator at %ld\n", error_position);
            temp_data[0] = ERROR_DOUBLE_OPERATOR;
            break;
        default:
            break;
    }
    return temp_data;
}

struct calc *parsing_str(const char *expr, uint64_t *len) {

    uint64_t *temp_data = check_correct_expr(expr, len);

    if (temp_data[0] != 0) {
        free(temp_data);
        return NULL;
    }   
    printf("STR IS FINISHED SUCCESSFULLY\n");
    return NULL;

    struct calc *calc  = (struct calc *)malloc(sizeof(struct calc *));

    // FIX: REPLACE TO MORE READABLE NAME (MACRO)
    calc->stack_operations_n = temp_data[1]; 
    calc->stack_brackets_n = temp_data[2];
    calc->value = 0;

    free(temp_data);
    
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
