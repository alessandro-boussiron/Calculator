/*
** EPITECH PROJECT, 2026
** Calculator
** File description:
** operation
*/

#include "calculator.h"

const operations_t operations[] = {
    {is_add, add, ADDITION},
    {is_div, do_div, DIVISION},
    {is_mul, mul, MULTIPLY},
    {is_sub, sub, SUBSRACT},
    {is_pow, pow, POWER},
    {NULL, NULL, UNDEFINED},
};

double add(double a, double b)
{
    return a + b;
}

double sub(double a, double b)
{
    return a - b;
}

double mul(double a, double b)
{
    return a * b;
}

double do_div(double a, double b)
{
    return (b != 0) ? a / b : 0;
}