# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ztawanna <ztawanna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/07 15:04:32 by ztawanna          #+#    #+#              #
#    Updated: 2020/08/08 01:48:12 by ztawanna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_parse.c ft_print_char.c ft_print_int_ptr.c ft_print_x.c \
ft_printf_utils.c ft_printf.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

%.o: %.c ft_printf.h
	clang $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
