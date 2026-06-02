/*
** EPITECH PROJECT, 2026
** Calculator
** File description:
** checks
*/

#include "calculator.h"

bool is_add(char *s)
{
    if (!s)
        return false;
    return (*s == '+');
}

bool is_sub(char *s)
{
    if (!s)
        return false;
    return (*s == '-' && s[1] == 0);
}

bool is_mul(char *s)
{
    if (!s)
        return false;
    return (*s == '*');
}

bool is_div(char *s)
{
    if (!s)
        return false;
    return (*s == '/');
}

bool is_pow(char *s)
{
    if (!s)
        return false;
    return (*s == '^');
}
