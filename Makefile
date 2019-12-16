CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME=libftprintf.a
OUT1=./ft_printf_output.out
OUT2=./printf_output.out


all:
	$(CC) -g3 testft_printf.c -D PRINT=ft_printf $(NAME)  -o $(OUT1)
	$(CC) -g3 testft_printf.c -D PRINT=printf  $(NAME)  -o $(OUT2)
	sh launch.sh

clean:
	rm $(OUT1) $(OUT2)

flcean: clean
	rm 