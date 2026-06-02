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
    {NULL, UNDEFINED},
};

static double add(double a, double b) {
    return a + b;
}

static double sub(double a, double b) {
    return a - b;
}

static double mul(double a, double b) {
    return a * b;
}

static double do_div(double a, double b) {
    return (b != 0) ? a / b : 0;
}