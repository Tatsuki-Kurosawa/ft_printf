# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 17:11:17 by kurosawaits       #+#    #+#              #
#    Updated: 2022/11/16 21:15:34 by kurosawaits      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	

OBJS	=	$(SRCS:.c=.o)
B_OBJS	=	$(B_SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

ifdef FLAG
OBJS	+= $(B_OBJS) 
endif

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:	
		rm -f $(OBJS) $(B_OBJS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all

bonus:
		@make FLAG=1

.PHONY:	all clean fclean re
