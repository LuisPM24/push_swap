/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:43:21 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/26 17:18:58 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_args(int argc, char **argv)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	else
		return (&argv[1]);
}

void	load_stack(t_stack *a, char **args)
{
	int	count;

	count = 0;
	while (args[count])
	{
		add_to_stack(a, ft_atoi(args[count]));
		count++;
	}
}

void	fsin(int argc, char **args)
{
	if (argc == 2)
		free_split(args);
}

void	free_split(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		free(split[count++]);
	free(split);
}
