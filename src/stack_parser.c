/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:47:31 by lupalomi          #+#    #+#             */
/*   Updated: 2026/05/08 09:50:28 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	strategy_parser(t_stack *stack, char **argv, int *position)
{
	if (ft_strcmp(argv[(*position)], "--adaptative") == 0)
	{
		stack->strategy = 0;
		(*position)++;
	}
	else if (ft_strcmp(argv[(*position)], "--simple") == 0)
	{
		stack->strategy = 1;
		(*position)++;
	}
	else if (ft_strcmp(argv[(*position)], "--medium") == 0)
	{
		stack->strategy = 2;
		(*position)++;
	}
	else if (ft_strcmp(argv[(*position)], "--complex") == 0)
	{
		stack->strategy = 3;
		(*position)++;
	}
}

static void	bench_parser(t_stack *stack, char **argv, int *position)
{
	if (ft_strcmp(argv[(*position)], "--bench") == 0)
	{
		stack->bench = 1;
		(*position)++;
	}
}

void	stack_parser(t_stack *stack, char **argv, int *position)
{
	if (!argv[(*position)])
		return ;
	bench_parser(stack, argv, position);
	if (!argv[(*position)])
		return ;
	strategy_parser(stack, argv, position);
	if (!argv[(*position)])
		return ;
	strategy_parser(stack, argv, position);
}
