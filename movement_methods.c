/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_methods.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:58:41 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/23 13:40:26 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
}

void	push_stack(t_stack *stack1, t_stack *stack2)
{
	t_node	*top_stack2;

	if (!stack2 || stack2->size == 0)
		return ;
	top_stack2 = stack2->top;
	stack2->top = top_stack2->next;
	if (stack2->top)
		stack2->top->prev = NULL;
	stack2->size--;
	top_stack2->next = stack1->top;
	if (stack1->top)
		stack1->top->prev = top_stack2;
	stack1->top = top_stack2;
	top_stack2->prev = NULL;
	stack1->size++;
}

void	rotate_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	stack->top->prev = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}
