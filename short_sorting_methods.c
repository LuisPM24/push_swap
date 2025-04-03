/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorting_methods.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:44:10 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/30 14:14:59 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		swap_a(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first < third && third < second)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (second < first && first < third)
		swap_a(a);
	else if (second < third && third < first)
		rotate_a(a);
	else if (third < first && first < second)
		reverse_rotate_a(a);
	else if (third < second && second < first)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
}

static void	pwm_for_five(t_stack *a, t_stack *b)
{
	int		signal;
	float	mean;
	t_node	*current;

	while (3 < a->size)
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

static void	return_to_a(t_stack *a, t_stack *b)
{
	while (a->size < 5)
	{
		if (b->top->value < a->top->value)
			push_a(a, b);
		else if (a->top->next->value > b->top->value)
		{
			rotate_a(a);
			push_a(a, b);
			reverse_rotate_a(a);
		}
		else if (b->top->value < a->top->next->next->value)
		{
			rotate_a(a);
			rotate_a(a);
			push_a(a, b);
			reverse_rotate_a(a);
			reverse_rotate_a(a);
		}
		else
		{
			reverse_rotate_a(a);
			push_a(a, b);
			rotate_a(a);
		}
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	pwm_for_five(a, b);
	sort_three(a);
	return_to_a(a, b);
	if (!is_sorted(a))
		rotate_a(a);
}
