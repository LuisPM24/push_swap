/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:36:45 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/04 23:43:49 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_hex_back(char *buffer, unsigned int nb, char *hex_digits)
{
	int	i;

	i = 15;
	buffer[i] = '\0';
	if (nb == 0)
	{
		buffer[--i] = '0';
	}
	while (nb > 0)
	{
		buffer[--i] = hex_digits[nb % 16];
		nb /= 16;
	}
	return (i);
}

void	ft_puthex(unsigned int nb, int *output)
{
	char	buffer[16];
	int		start;

	start = write_hex_back(buffer, nb, "0123456789abcdef");
	ft_putstr(buffer + start, output);
}

void	ft_putupphex(unsigned int nb, int *output)
{
	char	buffer[16];
	int		start;

	start = write_hex_back(buffer, nb, "0123456789ABCDEF");
	ft_putstr(buffer + start, output);
}
