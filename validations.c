/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:29:22 by lpalomin          #+#    #+#             */
/*   Updated: 2025/03/27 10:46:32 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	count;

	if (!str || *str == '\0')
		return (0);
	count = 0;
	if (str[count] == '-' || str[count] == '+')
		count++;
	if (!str[count])
		return (0);
	while (str[count])
	{
		if (str[count] < '0' || str[count] > '9')
			return (0);
		count++;
	}
	return (1);
}

int	is_duplicate(t_stack *a, int value)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	validate_args(char **args, t_stack *a)
{
	int		count;
	long	nbr;

	count = 0;
	while (args[count])
	{
		if (!is_valid_number(args[count]))
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
