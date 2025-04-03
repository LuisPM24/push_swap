/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:59:38 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/01 18:41:50 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_position(t_node *node, t_stack *a)
{
	int		count;
	t_node	*current;

	count = 1;
	current = a->top;
	while (current->value != node->value && current)
	{
		current = current->next;
		count++;
	}
	return (count);
}

int	calc_cost(t_node *node, t_stack *a)
{
	int		pos;
	int		cost;
	int		condition;

	pos = calculate_position(node, a);
	cost = 0;
	condition = ((a->size) / 2) + 1;
	if (node->value != a->top->value)
	{
		if (pos <= condition)
			cost = pos - 1;
		else if (pos > condition)
			cost = (a->size - pos) + 1;
	}
	return (cost);
}

void	assign_all_costs(t_stack *a, t_stack *b)
{
	int		cost_a;
	int		cost_b;
	t_node	*best;
	t_node	*current;

	cost_a = 0;
	cost_b = 0;
	current = b->top;
	while (current)
	{
		best = current->best_friend;
		cost_b = calc_cost(current, b);
		cost_a = calc_cost(best, a);
		current->cost = cost_a + cost_b;
		current = current->next;
	}
}

t_node	*select_winner(t_stack *b)
{
	t_node	*current;
	t_node	*winner_node;

	current = b->top;
	winner_node = NULL;
	while (current)
	{
		if (winner_node == NULL || current->cost < winner_node->cost)
			winner_node = current;
		current = current->next;
	}
	return (winner_node);
}

void	print_costs(t_stack *b)
{
	int		node_value;
	int		cost;
	int		best;
	t_node	*current;

	current = b->top;
	while (current)
	{
		node_value = current->value;
		cost = current->cost;
		best = current->best_friend->value;
		ft_printf("node: %i ; cost: %i ; best: %i\n", node_value, cost, best);
		current = current->next;
	}
}
