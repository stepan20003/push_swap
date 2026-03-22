NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	=	main.c \
			disorder_fuct.c \
			error.c \
			parse.c \
			print_bench.c \
			smallsort.c \
			sortfunctions.c \
			sortfunctions2.c \
			sortfunction3.c \
			stack_list.c \
			stack_utils.c \
			simple_sort.c \
			medium_sort.c \
			complex_sort.c \
			util.c \
			ft_isdigit.c \
			ft_split.c \
			ft_putchar.c \
			ft_putstr.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re