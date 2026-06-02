/*
** EPITECH PROJECT, 2026
** Calculator
** File description:
** checks
*/

#include "calculator.h"

const operations_t operations[] = {
    {is_add, ADDITION},
    {is_div, DIVISION},
    {is_mul, MULTIPLY},
    {is_sub, SUBSRACT},
    {is_pow, POWER},
    {NULL, UNDEFINED},
};

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

bool is_lparen(char *s)
{
    return s && (*s == '(');
}

bool is_rparen(char *s)
{
    return s && (*s == ')');
}

bool is_operator(char *s)
{
    return s && (is_add(s) || is_sub(s) || is_mul(s) || is_div(s) || is_pow(s));
}