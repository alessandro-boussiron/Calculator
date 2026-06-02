/*
** EPITECH PROJECT, 2026
** Calculator
** File description:
** main
*/

#include "calculator.h"

int main(int ac, char **av)
{
    ast_t *ast = init_ast(&av[1]);

    (void)ac;
    return EXIT_SUCCESS;
}
