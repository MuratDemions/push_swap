NAME = push_swap

CHECKER = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = args.c flag_parser.c func_helperone.c str_and_error.c disorder.c \
       push.c swap.c rotate.c r_rotate.c stack_utils.c move_counter.c \
	   index_stack.c is_sorted.c max_bits.c \
       simple.c radix_sort.c chunk_short.c adaptive.c

COMMON_OBJS = $(SRCS:.c=.o)

MAIN_OBJ = main.o

CHECKER_OBJ = checker.o

all: $(NAME)

$(NAME): $(COMMON_OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(MAIN_OBJ) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(COMMON_OBJS) $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(CHECKER_OBJ) -o $(CHECKER)

clean:
	rm -f $(COMMON_OBJS) $(MAIN_OBJ) $(CHECKER_OBJ)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
