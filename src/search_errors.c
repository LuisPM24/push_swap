/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 12:08:19 by lupalomi          #+#    #+#             */
/*   Updated: 2026/05/12 12:59:07 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	limit_comprobation(char *str, long *lnbr, int *count,
	int *sign)
{
	while (str[(*count)])
	{
		if (!ft_isdigit(str[(*count)]))
			return (0);
		(*lnbr) = (*lnbr) * 10 + (str[(*count)] - '0');
		if ((*sign) == 1 && (*lnbr) > INT_MAX)
			return (0);
		if ((*sign) == -1 && -(*lnbr) < INT_MIN)
			return (0);
		(*count)++;
	}
	return (1);
}

static int	valid_int(char *str)
{
	int		count;
	int		sign;
	long	lnbr;

	if (!str || !str[0])
		return (0);
	count = 0;
	sign = 1;
	lnbr = 0;
	if (str[count] == '+' || str[count] == '-')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	if (!ft_isdigit(str[count]))
		return (0);
	return (limit_comprobation(str, &lnbr, &count, &sign));
}

static int	search_repetitions(char **argv, int position)
{
	int	count;

	count = 1;
	while (argv[position] && argv[position + count])
	{
		if ((position == 1) && is_flag(argv[position])
			&& ft_strcmp(argv[position], argv[position + count]) == 0)
			return (1);
		else if (!is_flag(argv[position])
				&& ft_atoi(argv[position]) == ft_atoi(argv[position + count]))
				return (1);
		count++;
	}
	return (0);
}

int	search_errors(char **argv)
{
	int	count;

	count = 1;
	while (argv[count])
	{
		if ((count == 1 || count == 2))
		{
			if ((!valid_int(argv[count]) && !is_flag(argv[count]))
				|| search_repetitions(argv, count))
				return (1);
		}
		else if (!valid_int(argv[count]) || search_repetitions(argv, count))
			return (1);
		count++;
	}
	return (0);
}
