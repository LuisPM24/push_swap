/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:26:48 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/05 15:57:59 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*last;

	if (!*a || !(*a)->next)
		return ;
	last = last_node(*a);
	last->next = *a;
	*a = last;
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	t_node	*last;

	if (!*b || !(*b)->next)
		return ;
	last = last_node(*b);
	last->next = *b;
	*b = last;
	ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
