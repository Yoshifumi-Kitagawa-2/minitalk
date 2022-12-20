# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:56:04 by yokitaga          #+#    #+#              #
#    Updated: 2022/12/20 16:50:30 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(OBJS_1) $(OBJS_2)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = $(PWD)/libft
LIBFT = $(LIBFTDIR)/libft.a
OBJS_1 = server
OBJS_2 = client

ifndef WITH_BONUS
SRCS_1 = server.c
SRCS_2 = client.c
HEADER = minitalk.h 
endif

ifdef WITH_BONUS
SRCS_1 = server_bonus.c
SRCS_2 = client_bonus.c
HEADER = minitalk_bonus.h 
endif

all: $(NAME)

$(NAME): $(SRCS_1) $(SRCS_2) $(HEADER) $(LIBFT)
	$(CC) $(SRCS_1) $(LIBFT) $(CFLAGS) -o $(OBJS_1)
	$(CC) $(SRCS_2) $(LIBFT) $(CFLAGS) -o $(OBJS_2)

$(LIBFT):
	cd $(LIBFTDIR) && make all

clean:
	rm -f $(NAME)

fclean: clean
	cd $(LIBFTDIR) && make fclean

re:fclean all

bonus: clean
	make WITH_BONUS=1

.PHONY:
	all clean bonus fclean re;