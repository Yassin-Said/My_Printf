/*
** EPITECH PROJECT, 2021
** my_printf2
** File description:
** other function of my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

void my_putu(va_list list, struct detail *det)
{
    unsigned int flo = va_arg(list, long long int);

    my_put_nbr(flo);
    det->spaces = 0;
}

int negtest(int nbr)
{
    if (nbr < 0) {
        my_putchar('-');
        nbr *= -1;
    }
    return (nbr);
}

void my_puts(va_list list, struct detail *det)
{
    char *str = va_arg(list, char *);

    if (str != NULL) {
        display_all_str(det, str);
    } else {
        my_putstr("(null)");
    }
}

void printoct(unsigned char ch, char *octbase, struct detail *det)
{
    my_putchar('\\');
    if (ch < 8) {
        my_putstr("00");
    } else if (ch < 33) {
        write(1, "0", 1);
    }
    my_putbase(ch, octbase, det, "\0");
}

void my_putc(va_list list, struct detail *det)
{
    int nbr = 1;
    char ch = va_arg(list, int);

    count_print(nbr, det->spaces);
    write(1, &ch, 1);
    det->spaces = 0;
}
