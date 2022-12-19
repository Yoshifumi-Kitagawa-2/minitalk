# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:56:04 by yokitaga          #+#    #+#              #
#    Updated: 2022/12/19 16:06:45 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(OBJS_1) $(OBJS_2)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = $(PWD)/libft
LIBFT = $(LIBFTDIR)/libft.a
SRCS_1 = server_bonus.c 
SRCS_2 = client_bonus.c
OBJS_1 = server
OBJS_2 = client

all: $(NAME)

$(NAME): $(SRCS_1) $(SRCS_2) $(LIBFT)
	$(CC) $(SRCS_1) $(LIBFT) $(CFLAGS) -o $(OBJS_1)
	$(CC) $(SRCS_2) $(LIBFT) $(CFLAGS) -o $(OBJS_2)

$(LIBFT):
	cd $(LIBFTDIR) && make all

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean

.PHONY:
	all clean bonus fclean re;