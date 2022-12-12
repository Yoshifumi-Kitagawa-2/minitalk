NAME = $(OBJS_1) $(OBJS_2)
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_1 = server_v2.c utils.c
SRCS_2 = client_v2.c utils.c

OBJS_1 = server
OBJS_2 = client

all: $(NAME)

$(NAME): $(SRCS_1) $(SRCS_2)
	$(CC) $(SRCS_1) $(CFLAGS) -o $(OBJS_1)
	$(CC) $(SRCS_2) $(CFLAGS) -o $(OBJS_2)

$(LIBFT):
	cd $(LIBFTDIR) && make all

.PHONY:
	all clean bonus fclean re;

clean:
	rm -f $(NAME)
