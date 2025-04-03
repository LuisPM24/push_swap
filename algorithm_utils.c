/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:29:05 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/29 13:16:12 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	calc_mean_value(t_stack *a)
{
	int		count;
	int		sum;
	float	mean_value;
	t_node	*current;

	count = 0;
	sum = 0;
	current = a->top;
	while (count < a->size)
	{
		sum += current->value;
		current = current->next;
		count++;
	}
	mean_value = (sum / a->size);
	return (mean_value);
}

void	push_with_mean(t_stack *a, t_stack *b)
{
	int		signal;
	float	mean;
	t_node	*current;

	while (5 < a->size)
	{
		signal = 0;
		mean = calc_mean_value(a);
		while (!signal)
		{
			current = a->top;
			if (current->value < mean)
			{
				push_b(b, a);
				signal = 1;
			}
			else
				rotate_a(a);
		}
	}
}
