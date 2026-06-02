/*
** EPITECH PROJECT, 2026
** Calculator
** File description:
** ast_utils
*/

#include "calculator.h"

int count_args(char **args)
{
    int i = 0;
    if (!args)
        return 0;
    while (args[i])
        i++;
    return i;
}
