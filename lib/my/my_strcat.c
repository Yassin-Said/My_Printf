/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** return the concatenation of two str
*/

#include <stddef.h>

int my_strlen(char *);

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int i_2 = my_strlen(dest);

    while((src != NULL) && (src[i] != '\0')) {
        dest[i_2] = src[i];
        i++;
        i_2++;
    }
    return (dest);
}
