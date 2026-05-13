/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:30:17 by lupalomi          #+#    #+#             */
/*   Updated: 2026/05/13 12:30:18 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		free(split[count++]);
	free(split);
}

void	fsin(int argc, char **argv, char **split)
{
	int count;

	count = 1;
	while (argv[count] && is_flag(argv[count]))
		count++;
	if (argc - count == 1)
		free_split(split);
}