/*
** EPITECH PROJECT, 2021
** my
** File description:
** prototype of lib functions
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef PROTOTYPES_H_
    #define PROTOTYPES_H_

struct detail {
    char c;
    int spaces;
    const char *str;
    int *index;
    int htg;
    int point;
};

struct flag2
{
    char c;
    void (*fonct)(long unsigned int, char *, struct detail *, char *ext);
    char base[17];
    char ext[3];
};

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(const char *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_isprime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *scr);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
char *my_realloc2(char *tab);
int my_tablen(char **tab);
char **my_tabcpy(char **tab,char **tab2);
char *str_format(char *);
char *str_update(char *str);
char *str_unformat(char *str);
char *str_add(char *value_1, char *value_2);
char **pop_tab(char **str, int nb);
char *pop_str(char *str, int nb);
char *char_lower(char *str, char *str2);
char *char_greater(char *str, char *str2);
char *niv_mul(char *str, int i, int *incr_str);
char *is_null(char *str);
char *suppr(char *str);
int c_in_sign_or_base(char expr, char *sin_bas);
int banned_expr_b(char *expr, int i);
int banned_expr_s(char *expr, int i, char *sign);
void my_putfloat(float nbr);
void my_putu(va_list list, struct detail *det);
int negtest(int nbr);
void my_puts(va_list list, struct detail *det);
void printoct(unsigned char ch, char *octbase, struct detail *det);
void my_putc(va_list list, struct detail *det);
void my_putbase(long unsigned int nbr, char *base, struct detail *det, char *ext);
void my_putss(va_list list, struct detail *det);
void charspe(void);
int my_printf(const char *format, ...);
int count_print(int nb, int spaces);
int count_print_str(char *str, int spaces);
int is_nbr(int nb);
int format_nbr(const char *format, int *i);
void my_point(va_list list, struct detail *det);
void is_point(struct detail *det);
void put_zero(int nb, struct detail *det);
void display_all_base(struct detail *det, char *res, char *ext);
void display_all_nbr(struct detail *det, int res);
void display_all_str(struct detail *det, char *res);

#endif
