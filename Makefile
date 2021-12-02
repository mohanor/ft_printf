CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = 	ft_put_x.c ft_putchar.c ft_putnbr.c ft_putnbr_base.c ft_putnbr_unsigned.c ft_putstr.c ft_address_hex.c ft_printf.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) ft_printf.h
	ar -rcs $@ $^

clean:
	rm -rf $(OBJ)

re: fclean all
	rm -rf $(OBJ)

fclean: clean
	rm  $(NAME)

com:
	$(CC) $(FLAGS) main.c $(NAME)