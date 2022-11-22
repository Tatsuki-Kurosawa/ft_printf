# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 17:11:17 by kurosawaits       #+#    #+#              #
#    Updated: 2022/11/22 13:43:23 by kurosawaits      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_printf.c		\
			ft_printfput.c	\
			ft_printfstr.c	\
			ft_printfxput.c

OBJS	=	$(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:	
		rm -f $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
