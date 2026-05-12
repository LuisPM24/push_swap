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

static int	parse_bench(t_stack *stack, char *arg)
{
	if (ft_strcmp(arg, "--bench") == 0)
	{
		stack->bench = 1;
		return (1);
	}
	return (0);
}

static int	parse_strategy(t_stack *stack, char *arg)
{
	if (ft_strcmp(arg, "--adaptative") == 0)
		stack->strategy = 0;
	else if (ft_strcmp(arg, "--simple") == 0)
		stack->strategy = 1;
	else if (ft_strcmp(arg, "--medium") == 0)
		stack->strategy = 2;
	else if (ft_strcmp(arg, "--complex") == 0)
		stack->strategy = 3;
	else
		return (0);
	return (1);
}

void	stack_parser(t_stack *stack, char **argv, int *position)
{
	int	parsed;
	int	strategy_found;

	strategy_found = 0;
	while (argv[*position])
	{
		parsed = 0;
		if (parse_bench(stack, argv[*position]))
			parsed = 1;
		else if (parse_strategy(stack, argv[*position]))
		{
			if (strategy_found)
				return (print_error(stack));
			strategy_found = 1;
			parsed = 1;
		}
		if (!parsed)
			break ;
		(*position)++;
	}
}
