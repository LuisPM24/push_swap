/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_methods.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:22:48 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/23 13:35:29 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack *b)
{
	swap_stack(b);
	ft_printf("sb\n");
}

void	push_b(t_stack *b, t_stack *a)
{
	push_stack(b, a);
	ft_printf("pb\n");
}

void	rotate_b(t_stack *b)
{
	rotate_stack(b);
	ft_printf("rb\n");
}

void	reverse_rotate_b(t_stack *b)
{
	reverse_rotate_stack(b);
	ft_printf("rrb\n");
}
