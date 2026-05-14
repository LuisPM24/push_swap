/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimun_extraction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 10:56:46 by lupalomi          #+#    #+#             */
/*   Updated: 2026/05/14 10:56:48 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_minimun_position(t_stack *stack)
{
	t_node  		*current;
	int			  	minimun;
	unsigned int	position;
	unsigned int	min_pos;

	current = stack->head;
	minimun = current->value;
	position = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < minimun)
		{
			minimun = current->value;
			min_pos = position;
		}
		current = current->next;
		position++;
	}
	return (min_pos);
}

static void move_minimun_to_head(t_stack *stack)
{
	unsigned int	position;

	position = get_minimun_position(stack);
	if (position <= stack->size / 2)
	{
		while (position > 0)
		{
			ra(stack);
			position--;
		}
	}
	else
	{
		while (position < stack->size)
		{
			rra(stack);
			position++;
		}
	}
}

void    minimun_extraction(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->disorder == 0)
		return ;
	while (stack_a->size > 0)
	{
		move_minimun_to_head(stack_a);
		pb(stack_a, stack_b);
	}
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
