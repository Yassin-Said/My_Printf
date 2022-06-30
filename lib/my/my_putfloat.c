/*
** EPITECH PROJECT, 2021
** my_putfloat
** File description:
** display float numbers
*/

#include "my.h"

void my_putfloat(float nbr)
{
    my_put_nbr(nbr / 1);
    nbr = nbr - (nbr / 1);
    my_putchar('.');
}
