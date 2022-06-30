##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile for printf
##

CC = gcc
SRC     =	my_printf.c	\
		my_printf2.c	\
		my_printf3.c	\
		my_printf4.c	\
                my_printf5.c    \
		lib/my/my_compute_power_rec.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_revstr.c	\
		lib/my/my_putstr.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_strlen.c

OBJ 	=	$(SRC:.c=.o)
CFLAGS = -W -Wall -Wextra -Werror -I ./includes/
NAME    =       libmy.a

all : $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)	\
        rm -f *~

fclean: clean
	rm -f debug	\
	rm debug	\
	rm -f libmy.a	\
        rm *.gcno       \
	rm *.gcda

re: fclean all

tests_run:
	gcc -o debug -I ./includes/ $(SRC) tests/*.c -lcriterion --coverage
