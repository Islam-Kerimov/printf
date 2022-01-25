# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctanton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 14:50:38 by ctanton           #+#    #+#              #
#    Updated: 2021/01/12 17:30:59 by ctanton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC =	ft_printf.c \
		ft_parsing_flags.c \
		ft_processor.c \
		ft_print_d_or_i.c \
		ft_print_u.c \
		ft_print_x_or_xbig.c \
		ft_print_p.c \
		ft_print_s.c \
		ft_print_c.c \
		ft_print_percent.c \
		ft_printf_utils.c \
		ft_printf_utils_itoa.c \

OBJ =	${SRC:.c=.o}

CC =	gcc

CFLAGS =	-Wall -Wextra -Werror -c

HEADER =	libftprintf.h

%.o: %.c	$(HEADER)
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
