/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 09:32:12 by lupalomi          #+#    #+#             */
/*   Updated: 2026/05/13 09:32:13 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_repetitions(char **argv, int position)
{
	int	count;
	int	rep;

	count = 0;
	rep = 0;
	while (argv[count])
	{
		if (ft_strcmp(argv[position], argv[count]) == 0)
			rep++;
		count++;
	}
	if (rep <= 1)
		return (0);
	return (1);
}

static void	manage_flag(t_stack *stack, char *str)
{
	if (!ft_strcmp("--simple", str))
		stack->strategy = 1;
	else if (!ft_strcmp("--medium", str))
		stack->strategy = 2;
	else if (!ft_strcmp("--complex", str))
		stack->strategy = 3;
	else if (!ft_strcmp("--bench", str))
		stack->bench = 1;
	stack->flags++;
}

char	**parse_args(t_stack *stack, int argc, char **argv)
{
	int		count;

	count = 1;
	// lectura de flags
	while (argv[count] && is_flag(argv[count]))
	{
		if (count > 2 || search_repetitions(argv, count)
			|| (stack->flags != 0
			&& is_strat(argv[count]) == is_strat(argv[count - 1])))
			print_error(stack);
		manage_flag(stack, argv[count]);
		count++;
	}
	// lectura de numeros
	if (argc - count == 1)
		return (ft_split(argv[count], ' '));
	return (&argv[count]);
}