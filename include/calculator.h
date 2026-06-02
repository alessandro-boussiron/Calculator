/*
** EPITECH PROJECT, 2026
** Calculator
** File description:
** calculator
*/

#ifndef CALCULATOR_H_
    #define CALCULATOR_H_
    #include <stddef.h>
    #include <stdbool.h>
    #include <math.h>

    #define EXIT_SUCCESS (int)(0)
    #define EXIT_ERROR (int)(84)

    #define OPERATION_COUNT (int)(5)

// Typedefs

typedef enum {
    UNDEFINED,
    VALUE,
    ADDITION,
    SUBSRACT,
    DIVISION,
    MULTIPLY,
    POWER
} type_t;

typedef struct ast {
    type_t type;
    double value;
    struct ast *left;
    struct ast *right;
} ast_t;

typedef bool (*check_fnc)(char *);
typedef struct operations {
    check_fnc function;
    type_t type;
} operations_t;

// Functions

// AST
ast_t *init_ast(char **args);

// Utils
int count_args(char **args);

// Checks
bool is_operator(char *s);
bool is_add(char *s);
bool is_sub(char *s);
bool is_mul(char *s);
bool is_div(char *s);
bool is_pow(char *s);
bool is_lparen(char *s);
bool is_rparen(char *s);

#endif /* !CALCULATOR_H_ */
