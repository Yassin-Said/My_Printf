/*
** EPITECH PROJECT, 2021
** my_printf5
** File description:
** function for my_printf
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void display_all_base(struct detail *det, char *res, char *ext)
{
    if (det->htg == 1) {
        det->spaces = det->spaces - my_strlen(ext);
    }
    put_zero(my_compute_power_rec(10, (my_strlen(res) - 1)), det);
    count_print_str(res, det->spaces);
    if (det->htg == 1) {
        det->spaces = det->spaces - my_strlen(ext);
        my_putstr(ext);
    }
    for (; det->point > 0; det->point = det->point - 1) {
        my_putchar('0');
        det->spaces--;
    }
    my_putstr(my_revstr(res));
    free(res);
}

void display_all_str(struct detail *det, char *res)
{
    int i = 0;
    char *str = malloc(sizeof(char) * my_strlen(res));

    if (det->point < 1) {
        count_print_str(res, det->spaces);
        my_putstr(res);
    } else {
        for (; det->point > 0; det->point = det->point - 1) {
            str[i] = res[i];
            i++;
        }
        str[i] = '\0';
        count_print_str(str, det->spaces);
        my_putstr(str);
        free(str);
    }
}

void display_all_nbr(struct detail *det, int res)
{
    int sign = 0;

    if (res < 0) {
        res *= -1;
        sign = 1;
    }
    put_zero(res, det);
    count_print(res, det->spaces);
    for (; det->point > 0; det->point = det->point - 1) {
        my_putchar('0');
        det->spaces--;
    }
    if (sign == 1)
        my_putchar('-');
    my_put_nbr(res);
}
