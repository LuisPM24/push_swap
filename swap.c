/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:36:43 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/05 12:37:47 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first two elements at the top of stack A
void	sa(t_node **a)
{
	int	tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	ft_printf("sa\n");
}

// Swap the first two elements at the top of stack B
void	sb(t_node **b)
{
	int	tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	ft_printf("sb\n");
}

// Swap the first two elements at the top of both stacks A and B
void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}
