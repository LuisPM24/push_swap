/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:40:55 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/03 18:20:20 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_bfs_and_cost(t_stack *b)
{
	t_node	*current;

	current = b->top;
	while (current)
	{
		current->cost = 0;
		current = current->next;
	}
}

void	assign_bf(t_stack *a, t_node *node)
{
	int		winner;
	t_node	*current;

	winner = 0;
	current = a->top;
	while (current)
	{
		if (current->value > node->value
			|| (winner == 0 && current->value - node->value > 0))
		{
			if ((current->value - node->value) < winner || winner == 0)
			{
				winner = current->value - node->value;
				node->best_friend = current;
			}
		}
		current = current->next;
	}
}

void	print_bfs(t_stack *a)
{
	int		best_friend;
	t_node	*current;

	best_friend = 0;
	current = a->top;
	while (current)
	{
		best_friend = current->best_friend->value;
		ft_printf("node: %i; bf: %i\n", current->value, best_friend);
		current = current->next;
	}
}

void	assign_all_bf(t_stack *a, t_stack *b)
{
	t_node	*current;

	current = b->top;
	reset_bfs_and_cost(a);
	while (current)
	{
		assign_bf(a, current);
		current = current->next;
	}
}
