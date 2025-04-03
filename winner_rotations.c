/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:45:26 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/02 16:16:01 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotations(t_node *node, t_stack *stack)
{
	while (stack->top->value != node->value)
	{
		if (stack->name == 'a')
			rotate_a(stack);
		else if (stack->name == 'b')
			rotate_b(stack);
	}
}

void	do_reverse_rotations(t_node *node, t_stack *stack)
{
	while (node->next && stack->top->value != node->value)
	{
		if (stack->name == 'a')
			reverse_rotate_a(stack);
		else if (stack->name == 'b')
			reverse_rotate_b(stack);
	}
	if (stack->name == 'a')
		reverse_rotate_a(stack);
	else if (stack->name == 'b')
		reverse_rotate_b(stack);
}

void	do_winner_movement(t_node *node, t_stack *stack)
{
	int	pos;
	int	condition;

	pos = calculate_position(node, stack);
	condition = ((stack->size) / 2) + 1;
	if (pos <= condition)
		do_rotations(node, stack);
	else if (pos > condition)
		do_reverse_rotations(node, stack);
}

t_node	*search_lesser_node(t_stack *a)
{
	t_node	*current;
	t_node	*lesser;

	current = a->top;
	lesser = NULL;
	while (current)
	{
		if (lesser == NULL || current->value < lesser->value)
			lesser = current;
		current = current->next;
	}
	return (lesser);
}

void	final_rotation(t_stack *a)
{
	t_node	*lesser;

	lesser = search_lesser_node(a);
	do_winner_movement(lesser, a);
}
