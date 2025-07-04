# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frckles <frckles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 22:59:16 by abisiani          #+#    #+#              #
#    Updated: 2025/07/04 14:22:48 by frckles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

CFLAGS=-Wall -Werror -Wextra

AR=ar rcs

CC=cc

NAME=libftprintf.a

TEST_EXECUTABLE=printf

SRC=

OBJ=$(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ_ALL)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(TEST_EXECUTABLE)

re: fclean all

test: re
	$(CC) $(CFLAGS) -o $(TEST_EXECUTABLE) ft_printf.c -L. -lftprintf
	./$(TEST_EXECUTABLE) "Test me\n" "and me" 
