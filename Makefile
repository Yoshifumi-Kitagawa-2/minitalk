NAME = $(OBJ_1)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = $(PWD)/libft 
LIBFT = $(LIBFTDIR)/libft.a
SRCS_1 = server.c
OBJS_1 = server

all: $(NAME)

$(NAME): $(SRCS_1) $(LIBFT)
	$(CC) $(SRCS_1) $(LIBFT) $(CFLAGS) -o $(OBJS_1)

$(LIBFT):
	cd $(LIBFTDIR) && make all

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean

.PHONY:
	all clean bonus fclean re;
