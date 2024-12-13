CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = get_next_line
NAME_BONUS = get_next_line_bonus

SRCS = \
	get_next_line.c			\
	get_next_line_utils.c

BONUS_SRCS = \
	get_next_line_bonus.c			\
	get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_OBJS)

re: fclean all


