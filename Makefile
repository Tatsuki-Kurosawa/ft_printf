# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 17:11:17 by kurosawaits       #+#    #+#              #
#    Updated: 2023/02/18 15:37:54 by kurosawaits      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS	= 	ft_printf.c			\
			ft_printftools.c	\
			ft_putaddress.c		\
			ft_putchar.c		\
			ft_putnbr.c

OBJS = $(SRCS:%.c=%.o)

CC   = cc

CFLAGS = -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re:			fclean	all

.PHONY:		all clean fclean re
