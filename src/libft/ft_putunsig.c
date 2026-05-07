/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:37:02 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/04 23:43:49 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsig(unsigned int nb, int *output)
{
	int				result;
	unsigned long	lnb;

	lnb = nb;
	if (lnb >= 10)
	{
		ft_putunsig(lnb / 10, output);
	}
	result = (lnb % 10) + '0';
	write(1, &result, 1);
	(*output)++;
}
