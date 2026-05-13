/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupalomi <lupalomi@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 11:49:13 by lupalomi          #+#    #+#             */
/*   Updated: 2026/05/13 11:49:16 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		count;

	result = 0;
	sign = 1;
	count = 0;
	if (str[count] == '+' || str[count] == '-')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (str[count])
	{
		if (str[count] < '0' || str[count] > '9')
			break ;
		result = result * 10 + (str[count] - '0');
		count++;
	}
	return (result * sign);
}
