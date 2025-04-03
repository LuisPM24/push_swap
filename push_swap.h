/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 10:55:10 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/02 18:11:46 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	struct s_node	*best_friend;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*top;
	int				size;
	char			name;
}	t_stack;

// push_swap.c
t_node	*new_node(int value);
void	add_to_stack(t_stack *stack, int value);
// stack_utils.c
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);
int		is_sorted(t_stack *a);
// movement_methods.c
void	swap_stack(t_stack *stack);
void	push_stack(t_stack *stack1, t_stack *stack2);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);
// a_methods.c
void	swap_a(t_stack *a);
void	push_a(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a);
void	reverse_rotate_a(t_stack *a);
// b_methods.c
void	swap_b(t_stack *b);
void	push_b(t_stack *b, t_stack *a);
void	rotate_b(t_stack *b);
void	reverse_rotate_b(t_stack *b);
// s_methods.c
void	swap_s(t_stack *a, t_stack *b);
void	rotate_r(t_stack *a, t_stack *b);
void	reverse_rotate_r(t_stack *a, t_stack *b);
// split_utils.c
char	**get_args(int argc, char **argv);
void	load_stack(t_stack *a, char **args);
void	fsin(int argc, char **args);
void	free_split(char **split);
// short_sorting_methods.c
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
// bf_utils.c
void	reset_bfs_and_cost(t_stack *b);
void	assign_bf(t_stack *a, t_node *node);
void	print_bfs(t_stack *a);
void	assign_all_bf(t_stack *a, t_stack *b);
// cost_utils.c
int		calculate_position(t_node *node, t_stack *a);
int		calc_cost(t_node *node, t_stack *a);
void	assign_all_costs(t_stack *a, t_stack *b);
t_node	*select_winner(t_stack *b);
void	print_costs(t_stack *b);
// winner_rotations.c
void	do_rotations(t_node *node, t_stack *stack);
void	do_reverse_rotations(t_node *node, t_stack *stack);
void	do_winner_movement(t_node *node, t_stack *stack);
t_node	*search_lesser_node(t_stack *a);
void	final_rotation(t_stack *a);
// algorithm_utils.c
float	calc_mean_value(t_stack *a);
void	push_with_mean(t_stack *a, t_stack *b);
// validations.c
int		is_valid_number(char *str);
int		is_duplicate(t_stack *a, int value);
int		validate_args(char **args, t_stack *a);
// algorithm.c
void	algorithm(t_stack *a, t_stack *b);
void	method_selector(t_stack *a, t_stack *b);
#endif
