# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 19:38:29 by yokitaga          #+#    #+#              #
#    Updated: 2022/12/12 15:25:51 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a 
SRCS		= ft_atoi.c ft_isdigit.c ft_putchar_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c 
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
OBJS		= $(SRCS:%.c=%.o)

all:		$(NAME)
$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
%.o : %.c
			$(CC) $(CFLAGS) -c $?
		
clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re