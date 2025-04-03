/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:19:45 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/29 11:19:59 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	while (stack->top)
	{
		temp = stack->top->next;
		free(stack->top);
		stack->top = temp;
	}
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	ft_printf("Stack %c (size %d):\n", stack->name, stack->size);
	current = stack->top;
	while (current)
	{
		ft_printf("   %d\n", current->value);
		current = current->next;
	}
}

int	is_sorted(t_stack *a)
{
	t_node	*current;

	current = a->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
