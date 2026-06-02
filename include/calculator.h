/*
** EPITECH PROJECT, 2026
** Calculator
** File description:
** calculator
*/

#ifndef CALCULATOR_H_
    #define CALCULATOR_H_
    #include <stddef.h>
    #include <stdbool.h>
    #include <math.h>

    #define EXIT_SUCCESS (int)(0)
    #define EXIT_ERROR (int)(84)


// Checks
bool is_add(char *s);
bool is_sub(char *s);
bool is_mul(char *s);
bool is_div(char *s);
bool is_pow(char *s);

#endif /* !CALCULATOR_H_ */
