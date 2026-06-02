/*
** EPITECH PROJECT, 2026
** Calculator
** File description:
** ast_utils
*/

#include "calculator.h"
#include <stdlib.h>

void destroy_ast(ast_t *node)
{
    if (!node)
        return;
    destroy_ast(node->left);
    destroy_ast(node->right);
    free(node);
}

int count_args(char **args)
{
    int i = 0;
    if (!args)
        return 0;
    while (args[i])
        i++;
    return i;
}
