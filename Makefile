NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

DIR = src
LIBFT_DIR = $(DIR)/libft

LIBFT = $(DIR)/$(LIBFT_DIR)/libft.a

SRCS = $(DIR)/push_swap.c \
       $(DIR)/disorder.c \
	   $(DIR)/push.c \
	   $(DIR)/swap.c \
	   $(DIR)/rotate.c \
	   $(DIR)/reserve_rotate.c \
	   $(DIR)/utils.c \
	   $(DIR)/stack_parser.c \
	   $(DIR)/args_parser.c \
	   $(DIR)/args_utils.c \
	   $(DIR)/split_utils.c \
	   $(DIR)/start_algorithm.c
       

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
