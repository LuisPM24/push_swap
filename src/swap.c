/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:36:43 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/05 14:39:45 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->head = second;
}

// Swap the first two elements of stack A
void	sa(t_stack *stack_a)
{
	swap_stack(stack_a);
	ft_printf("sa\n");
}

// Swap the first two elements of stack B
void	sb(t_stack *stack_b)
{
	swap_stack(stack_b);
	ft_printf("sb\n");
}

// Combine sa and sb
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	ft_printf("ss\n");
}
