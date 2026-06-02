/*
** EPITECH PROJECT, 2026
** Calculator
** File description:
** execute
*/

#include "calculator.h"

static apply_fnc get_apply(type_t type)
{
    for (int i = 0; operations[i].check != NULL; i++)
        if (operations[i].type == type)
            return operations[i].apply;
    return NULL;
}

double execute_expression(ast_t *node)
{
    apply_fnc apply = NULL;
    double result = 0;

    if (!node)
        return 0;
    if (node->type == VALUE)
        return node->value;
    if (node->left->type != VALUE)
        execute_expression(node->left);
    if (node->right->type != VALUE)
        execute_expression(node->right);
    apply = get_apply(node->type);
    if (!apply)
        return 0;
    result = apply(node->left->value, node->right->value);
    node->type = VALUE;
    node->value = result;
    return result;
}