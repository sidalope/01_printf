# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frckles <frckles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 22:59:16 by abisiani          #+#    #+#              #
#    Updated: 2025/07/15 12:17:01 by frckles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

CFLAGS=-Wall -Werror -Wextra

AR=ar rcs

CC=cc

NAME=libftprintf.a

TEST_EXECUTABLE=tests

SRC=ft_printf.c print_c.c print_s.c print_p.c #print_d.c print_i.c \
	print_u.c print_x.c print_X.c print_%.c

OBJ=$(SRC:.c=.o)

LIBFT=libft/libft.a

all: $(NAME)

libft/libft.a:
	make -C libft all

$(NAME): $(OBJ) $(LIBFT)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(TEST_EXECUTABLE)
	make -C libft fclean

re: fclean all

test: re
	$(CC) $(CFLAGS) -o $(TEST_EXECUTABLE) tests.c -L. -lftprintf -Llibft -lft
	./$(TEST_EXECUTABLE)
