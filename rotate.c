/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:36:36 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/05 12:38:04 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate stack A: shift all elements up by 1, first element becomes last
void	ra(t_node **a)
{
	t_node	*head;

	if (!*a || !(*a)->next)
		return ;
	head = *a;
	*a = (*a)->next;
	head->next = NULL;
	last_node(*a)->next = head;
	ft_printf("ra\n");
}

// Rotate stack B: shift all elements up by 1, first element becomes last
void	rb(t_node **b)
{
	t_node	*head;

	if (!*b || !(*b)->next)
		return ;
	head = *b;
	*b = (*b)->next;
	head->next = NULL;
	last_node(*b)->next = head;
	ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
