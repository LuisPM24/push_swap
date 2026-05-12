/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 13:12:38 by lupalomi          #+#    #+#             */
/*   Updated: 2026/05/12 13:01:22 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		strategy_selector(t_stack *stack)
{
	if (stack->disorder >= 50)
		stack->strategy = 3;
	else if (stack->disorder >= 20)
		stack->strategy = 2;
	else
		stack->strategy = 1;
}

void	start_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 0)
		return ;
	stack_a->disorder = disorder(stack_a);
	if (stack_a->strategy == 0)
		strategy_selector(stack_a);
	stack_b->size = 0;
	return ;
}
