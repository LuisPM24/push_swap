/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 11:11:41 by lupalomi          #+#    #+#             */
/*   Updated: 2026/05/13 11:11:42 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *stack, int value)
{
	t_node	*cur;

	cur = stack->head;
	while (cur)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}

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

int	valid_int(char *str)
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

int	validate_args(char **args, t_stack *a)
{
	int		count;
	long	nbr;

	count = 0;
	while (args[count])
	{
		if (!valid_int(args[count]))
			return (0);
		nbr = ft_atol(args[count]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		if (is_duplicate(a, nbr))
			return (0);
		add_to_stack(a, nbr);
		count++;
	}
	return (1);
}
