/*
** EPITECH PROJECT, 2026
** Calculator
** File description:
** ast
*/

#include "calculator.h"
#include <stdlib.h>

static ast_t *parse_lowest(char **args, int *pos, int size);

static ast_t *create_ast_node(type_t type, ast_t *left, ast_t *right)
{
    ast_t *node = malloc(sizeof(ast_t));

    if (!node)
        return NULL;
    node->type = type;
    node->value = 0;
    node->left = left;
    node->right = right;
    return node;
}

static ast_t *create_ast_value(double value)
{
    ast_t *node = malloc(sizeof(ast_t));

    if (!node)
        return NULL;
    node->type = VALUE;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static ast_t *parse_number(char **args, int *pos, int size)
{
    char *endptr = NULL;
    double val = 0;

    if (*pos >= size)
        return NULL;
    val = strtod(args[*pos], &endptr);
    if (!endptr || endptr == args[*pos])
        return NULL;
    (*pos)++;
    return create_ast_value(val);
}

static ast_t *parse_paren(char **args, int *pos, int size)
{
    ast_t *inner = NULL;

    (*pos)++;
    inner = parse_lowest(args, pos, size);
    if (!inner || *pos >= size || !is_rparen(args[*pos]))
        return NULL;
    (*pos)++;
    return inner;
}

static ast_t *parse_primary(char **args, int *pos, int size)
{
    if (*pos >= size)
        return NULL;
    if (is_lparen(args[*pos]))
        return parse_paren(args, pos, size);
    return parse_number(args, pos, size);
}

static ast_t *parse_power(char **args, int *pos, int size)
{
    ast_t *left = parse_primary(args, pos, size);
    ast_t *right = NULL;

    if (!left || *pos >= size || !is_pow(args[*pos]))
        return left;
    (*pos)++;
    right = parse_power(args, pos, size);
    if (!right)
        return NULL;
    return create_ast_node(POWER, left, right);
}

static ast_t *parse_term(char **args, int *pos, int size)
{
    ast_t *left = parse_power(args, pos, size);
    ast_t *right = NULL;
    type_t op = UNDEFINED;

    if (!left)
        return NULL;
    while (*pos < size && (is_mul(args[*pos]) || is_div(args[*pos]))) {
        op = is_mul(args[*pos]) ? MULTIPLY : DIVISION;
        (*pos)++;
        right = parse_power(args, pos, size);
        if (!right)
            return NULL;
        left = create_ast_node(op, left, right);
    }
    return left;
}

static ast_t *parse_lowest(char **args, int *pos, int size)
{
    ast_t *left = parse_term(args, pos, size);
    ast_t *right = NULL;
    type_t op = UNDEFINED;

    if (!left)
        return NULL;
    while (*pos < size && (is_add(args[*pos]) || is_sub(args[*pos]))) {
        op = is_add(args[*pos]) ? ADDITION : SUBSRACT;
        (*pos)++;
        right = parse_term(args, pos, size);
        if (!right)
            return NULL;
        left = create_ast_node(op, left, right);
    }
    return left;
}

ast_t *init_ast(char **args)
{
    int pos = 0;
    int size = 0;

    if (!args)
        return NULL;
    size = count_args(args);
    if (size == 0)
        return NULL;
    return parse_lowest(args, &pos, size);
}
