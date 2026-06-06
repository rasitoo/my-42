NAME=libft
CC=cc
CFLAGS=-Wall -Werror -Wextra
SRCS=
OBJS=$(SRCS:.c=.o)
EXE=

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all
