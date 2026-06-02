/*
** EPITECH PROJECT, 2026
** Calculator
** File description:
** main
*/

#include "calculator.h"
#include <stdio.h>

int main(int ac, char **av)
{
    ast_t *ast = init_ast(&av[1]);

    (void)ac;
    printf("%f\n", execute_expression(ast));
    destroy_ast(ast);
    return EXIT_SUCCESS;
}
