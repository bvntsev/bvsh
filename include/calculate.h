#ifndef CALCULATE
#define CALCULATE

#include <stdint.h>

#define ERROR_INVALID_SYMBOL_PLACE          0x01
#define ERROR_UNKOWN_SYMBOL                 0x02
#define ERROR_DIVISION_BY_ZERO              0x03
#define ERROR_SINGLE_BRACKET                0x04
#define ERROR_NUMBER_STARTS_AT_ZERO         0x05
#define ERROR_DOUBLE_OPERATOR               0x06

// TEMPORARY !!!
#define VERIFY_MATH_OPERATOR_DIV                            \
    switch(expr[iter+1]){                                   \
        case '0':                                           \
            if (iter+2 < *len-1 && isdigit(expr[iter+2])){  \
                expr_code = ERROR_NUMBER_STARTS_AT_ZERO;    \
                error_position = iter+1;                    \
            }                                               \
            else {                                          \
                expr_code = ERROR_DIVISION_BY_ZERO;         \
                error_position = iter;                      \
            }                                               \
            break;                                          \
        case '/':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        case '|':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        case '*':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        case '+':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        case '-':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        case '&':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        case '^':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        }

#define VERIFY_MATH_OPERATOR                                \
    switch(expr[iter+1]){                                   \
        case '0':                                           \
            if (iter+2 < *len-1 && isdigit(expr[iter+2])){  \
                expr_code = ERROR_NUMBER_STARTS_AT_ZERO;    \
                error_position = iter+1;                    \
            }                                               \
            break;                                          \
        case '/':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        case '|':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        case '*':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        case '+':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        case '-':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        case '&':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        case '^':                                           \
            expr_code = ERROR_DOUBLE_OPERATOR;              \
            error_position = iter;                          \
            break;                                          \
        }

char verify_available_symbol(const char *expr);

struct calc *parsing_str(const char *expr, uint64_t *len);

struct calc{
    char ***stack_brackets;
    uint64_t stack_brackets_n;
    char ***stack_operations;
    uint64_t stack_operations_n;
    const char *user_str;
    uint64_t value;
};



#endif // !CALCULATE
