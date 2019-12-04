CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME=libftprintf.a

all:
	$(CC) -g3 testft_printf.c -D PRINT=ft_printf $(NAME)  -o ./ft_printf_output.out
	$(CC) -g3 testft_printf.c -D PRINT=printf  $(NAME)  -o ./printf_output.out
	sh launch.sh