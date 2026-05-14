/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:36:33 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/05 12:35:48 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_stack *stack1, t_stack *stack2)
{
	t_node	*node;

	if (!stack1 || !stack2 || !stack2->head)
		return ;
	node = stack2->head;
	stack2->head = node->next;
	stack2->size--;
	node->next = stack1->head;
	stack1->head = node;
	stack1->size++;
}

// Push the top element of stack B onto stack A
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push_stack(stack_a, stack_b);
	ft_printf("pa\n");
}

// Push the top element of stack A onto stack B
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push_stack(stack_b, stack_a);
	ft_printf("pb\n");
}