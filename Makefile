CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a

SRCS = \
	get_next_line.c			\
	get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	ar rcs $(NAME) $(OBJS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


