/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 09:19:45 by lupalomi          #+#    #+#             */
/*   Updated: 2026/05/15 09:19:58 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_range(int total)
{
	int	range;

	range = ft_sqrt(total) * 15 / 10;
	if (range < 2)
		range = 2;
	return (range);
}

static int	find_best_friend(t_stack *stack, unsigned int pushed,
	int range)
{
	t_node	*aux;
	int		position;
	int		first;
	int		last;

	aux = stack->head;
	position = 0;
	first = -1;
	last = -1;
	while (aux)
	{
		if (aux->index <= pushed + range)
		{
			if (first == -1)
				first = position;
			last = position;
		}
		aux = aux->next;
		position++;
	}
	if (first == -1)
		return (-1);
	if (first <= (int)stack->size - (int)last)
		return (first);
	return (last);
}

static void	move_position_to_head(t_stack *stack, unsigned int position)
{
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

void	push_chunks_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	position;
	int	range;
	int	pushed;
	int	index;

	range = get_chunk_range(stack_a->total_nbr);
	pushed = 0;
	while (stack_a->size > 0)
	{
		position = find_best_friend(stack_a, pushed, range);
		if (position != -1)
			move_position_to_head(stack_a, position);
		index = stack_a->head->index;
		pb(stack_a, stack_b);
		if (stack_b->head && index <= pushed)
			rb(stack_b);
		pushed++;
	}
}

void	chunks(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	assign_chunks_indexes(stack_a);
	push_chunks_to_b(stack_a, stack_b);
	push_chunks_to_a(stack_a, stack_b);
}
