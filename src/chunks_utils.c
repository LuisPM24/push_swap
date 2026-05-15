/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:54:54 by lupalomi          #+#    #+#             */
/*   Updated: 2026/05/14 17:55:07 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_chunks_indexes(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack->head;
	while (current)
	{
		index = 0;
		compare = stack->head;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

static int	get_maximun_position(t_stack *stack)
{
	t_node			*current;
	unsigned int	maximun;
	unsigned int	position;
	unsigned int	max_pos;

	current = stack->head;
	maximun = current->index;
	position = 0;
	max_pos = 0;
	while (current)
	{
		if (current->index > maximun)
		{
			maximun = current->index;
			max_pos = position;
		}
		current = current->next;
		position++;
	}
	return (max_pos);
}

static void	move_maximun_to_head(t_stack *stack)
{
	unsigned int	position;

	position = get_maximun_position(stack);
	if (position <= stack->size / 2)
	{
		while (position > 0)
		{
			rb(stack);
			position--;
		}
	}
	else
	{
		while (position < stack->size)
		{
			rrb(stack);
			position++;
		}
	}
}

void	push_chunks_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
	{
		move_maximun_to_head(stack_b);
		pa(stack_a, stack_b);
	}
}
