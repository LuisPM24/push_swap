/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:15:20 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/12 12:46:22 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				index;
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	char			name;
	t_node			*head;
	unsigned int	size;
	unsigned int	flags;
	int				bench;
	int				strategy;
	int				disorder;
}					t_stack;

void	print_stack(t_stack *stack);

// push_swap.c
void	add_to_stack(t_stack *stack, int value);

// stack_parser.c
void	stack_parser(t_stack *stack, char **argv, int *position);

// args_parser.c
char	**parse_args(t_stack *stack, int argc, char **argv);

// args_utils.c
int		valid_int(char *str);
int		validate_args(char **args, t_stack *a);

// split_utils.c
void	free_split(char **split);
void	fsin(int argc, char **argv, char **split);

// start_algorithm.c
void	start_algorithm(t_stack *stack_a, t_stack *stack_b);

// disorder.c
int		disorder(t_stack *stack);

// utils.c
t_node	*last_node(t_node *lst);
int		is_flag(char *str);
void	print_error(t_stack *stack);
int		is_strat(char *str);
void	free_stack(t_stack *stack);

// swap.c
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
// push.c
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
// rotate.c
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
// reverse_rotate.c
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif
