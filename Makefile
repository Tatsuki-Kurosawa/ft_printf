# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 17:11:17 by kurosawaits       #+#    #+#              #
#    Updated: 2022/12/12 16:25:21 by kurosawaits      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_printf.c		\
			ft_putchar.c	\
			ft_strchr.c		\
			ft_putxnbr_fd.c

OBJS	=	$(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
		$(MAKE) -C ./libft
		cp libft/libft.a $(NAME)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
