# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 22:59:16 by abisiani          #+#    #+#              #
#    Updated: 2025/06/10 22:35:01 by abisiani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

CFLAGS=-Wall -Werror -Wextra

AR=ar rcs

CC=cc

NAME=libftprintf.a

SRC=

OBJ=$(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ_ALL)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# test: re
# 	$(CC) $(CFLAGS) -o libft libft.c -L. -lft -lbsd
# 	./libft
