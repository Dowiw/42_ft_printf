# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmonjard <kmonjard@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 14:33:19 by kmonjard          #+#    #+#              #
#    Updated: 2025/06/30 14:33:21 by kmonjard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_COMPILER = gcc

C_FLAGS = -Wall -Wextra -Werror -c

C_FILES = ft_printf.c ft_putchar.c ft_putstr.c \
		ft_putint.c ft_putptr.c ft_puthex_low.c \
		ft_puthex_up.c ft_putint_u.c

O_FILES = $(C_FILES:.c=.o)

all: $(NAME)

$(NAME):
	$(C_COMPILER) $(C_FLAGS) $(C_FILES)
	ar rcs $(NAME) $(O_FILES)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
