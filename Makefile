# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 12:26:10 by lpalomin          #+#    #+#              #
#    Updated: 2025/04/01 19:08:23 by lpalomin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS =	push_swap.c \
		stack_utils.c \
		movement_methods.c \
		a_methods.c \
		b_methods.c \
		s_methods.c \
		split_utils.c \
		short_sorting_methods.c \
		bf_utils.c \
		cost_utils.c \
		winner_rotations.c \
		algorithm.c \
		algorithm_utils.c \
		validations.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft/

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
