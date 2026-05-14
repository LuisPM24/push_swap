/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:36:36 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/05 15:56:31 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	stack->head = first->next;
	last = stack->head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

// Rotate stack A: shift all elements up by 1, first element becomes last
void	ra(t_stack *stack_a)
{
	rotate_stack(stack_a);
	ft_printf("ra\n");
}

// Rotate stack B: shift all elements up by 1, first element becomes last
void	rb(t_stack *stack_b)
{
	rotate_stack(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_printf("rr\n");
}
