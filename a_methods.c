/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_methods.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:16:08 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/23 13:24:12 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	swap_stack(a);
	ft_printf("sa\n");
}

void	push_a(t_stack *a, t_stack *b)
{
	push_stack(a, b);
	ft_printf("pa\n");
}

void	rotate_a(t_stack *a)
{
	rotate_stack(a);
	ft_printf("ra\n");
}

void	reverse_rotate_a(t_stack *a)
{
	reverse_rotate_stack(a);
	ft_printf("rra\n");
}
