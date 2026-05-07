/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:36:51 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/04 23:43:49 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb, int *output)
{
	int		result;
	long	lnb;

	lnb = nb;
	if (lnb < 0)
	{
		write(1, "-", 1);
		*output += 1;
		lnb = -lnb;
	}
	if (lnb >= 10)
	{
		ft_putnbr(lnb / 10, output);
	}
	result = (lnb % 10) + '0';
	write(1, &result, 1);
	(*output)++;
}
