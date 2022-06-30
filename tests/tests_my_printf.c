/*
** EPITECH PROJECT, 2021
** test_my_printf
** File description:
** test my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_printf(const char *format, ...);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_str_format, .init=redirect_all_stdout)
{
    my_printf("ceci est %% un test %s", "digne d'un oscar");
    cr_assert_stdout_eq_str("ceci est % un test digne d'un oscar");
}

Test(my_printf, medium_str_format, .init=redirect_all_stdout)
{
    my_printf("ceci est le %d%S %s", 830, "magnifique test", "digne d'un oscar");
    cr_assert_stdout_eq_str("ceci est le 830magnifique test digne d'un oscar");
}

Test(my_printf, base_test, .init=redirect_all_stdout)
{
    my_printf("%d %c %b %s %X en hexadecimal%c", 830, '=', 830, "en binaire et", 830, '.');
    cr_assert_stdout_eq_str("830 = 1100111110 en binaire et 33E en hexadecimal.");
}

Test(my_printf, base_test_and_htg, .init=redirect_all_stdout)
{
    my_printf("%d %c %b %s %#X en hexadecimal%c", 830, '=', 830, "en binaire et", 830, '.');
    cr_assert_stdout_eq_str("830 = 1100111110 en binaire et 0X33E en hexadecimal.");
}


Test(my_printf, unsigned_and_neghex, .init=redirect_all_stdout)
{
    my_printf("un unsigned int peut prendre un nombre tel que %u se qui donne %X en hexadecimal", -40, -40);
    cr_assert_stdout_eq_str("un unsigned int peut prendre un nombre tel que 4294967256 se qui donne -28 en hexadecimal");
}

Test(my_printf, s_upper_case, .init=redirect_all_stdout)
{
    my_printf("ceci %S", "est un test j'pense");
    cr_assert_stdout_eq_str("ceci est un test j'pense");
}

Test(my_printf, S, .init=redirect_all_stdout)
{
    char test[] = {2, '\0'};
    char test2[] = {10, '\0'};
    
    my_printf("Bonjour le monde %S%S", test, test2);
    cr_assert_stdout_eq_str("Bonjour le monde \\002\\012");
}

Test(my_printf, spaces_case, .init=redirect_all_stdout)
{
    my_printf("ceci est le %10dième test", 15);
    cr_assert_stdout_eq_str("ceci est le         15ième test");
}

Test(my_printf, err_spaces_case, .init=redirect_all_stdout)
{
    my_printf("ceci est le %3dième test", 16545);
    cr_assert_stdout_eq_str("ceci est le 16545ième test");
}

Test(my_printf, point_case, .init=redirect_all_stdout)
{
    my_printf("ceci est le %.3dième test", 16235);
    cr_assert_stdout_eq_str("ceci est le 16235ième test");
}

Test(my_printf, point_case_2, .init=redirect_all_stdout)
{
    my_printf("ceci est le %.30dième test", 16235);
    cr_assert_stdout_eq_str("ceci est le 000000000000000000000000016235ième test");
}

Test(my_printf, point_case_3, .init=redirect_all_stdout)
{
    my_printf("ceci est le %10.7dième test", 16235);
    cr_assert_stdout_eq_str("ceci est le    0016235ième test");
}

Test(my_printf, point_case_4, .init=redirect_all_stdout)
{
    my_printf("ceci est le %10.2sième test", "16235");
    cr_assert_stdout_eq_str("ceci est le         16ième test");
}


Test(my_printf, point_case_in_hexa, .init=redirect_all_stdout)
{
    my_printf("ceci est le %.3Xième test", 16235);
    cr_assert_stdout_eq_str("ceci est le 3F6Bième test");
}


Test(my_printf, all_cases, .init=redirect_all_stdout)
{
    my_printf("il est%3dh et %s sur que %c'ai %d%% de chance de mourir", 24, "je suis", 'j', 24);
    cr_assert_stdout_eq_str("il est 24h et je suis sur que j'ai 24% de chance de mourir");
}

Test(my_printf, all_cases_2, .init=redirect_all_stdout)
{
    my_printf("je%5.4s trouver pourquoi, evirons %u test on crash, int max peut etre : %d","doit bien sur", 4, 2147483647);
    cr_assert_stdout_eq_str("je doit trouver pourquoi, evirons 4 test on crash, int max peut etre : 2147483647");
}

Test(my_printf, all_cases_3, .init=redirect_all_stdout)
{
    my_printf("le test %s à malhereusement pas crash je dirait que celui-ci à%3.2d%% de chance de crash", "précédent",5);
    cr_assert_stdout_eq_str("le test précédent à malhereusement pas crash je dirait que celui-ci à 05% de chance de crash");
}

Test(my_printf, basic, .init=redirect_all_stdout)
{
    my_printf("ceci est un test");
    cr_assert_stdout_eq_str("ceci est un test");
}

Test(my_printf, point_with_nothing, .init=redirect_all_stdout)
{
    my_printf("ceci est le %.dième test %.s", 20, "magique");
    cr_assert_stdout_eq_str("ceci est le 20ième test magique");
}
