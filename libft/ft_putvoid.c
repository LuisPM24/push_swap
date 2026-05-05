/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:37:12 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/04 23:43:48 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_hex_back(char *buffer, unsigned long lnb)
{
	char	*hex_digits;
	int		i;

	hex_digits = "0123456789abcdef";
	i = 18;
	buffer[i] = '\0';
	if (lnb == 0)
	{
		buffer[--i] = '0';
	}
	while (lnb > 0)
	{
		buffer[--i] = hex_digits[lnb % 16];
		lnb /= 16;
	}
	buffer[--i] = 'x';
	buffer[--i] = '0';
	return (i);
}

void	ft_putvoid(void *ptr, int *output)
{
	char	buffer[19];
	int		start;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		*output += 5;
	}
	else
	{
		start = write_hex_back(buffer, (unsigned long)ptr);
		ft_putstr(buffer + start, output);
	}
}
