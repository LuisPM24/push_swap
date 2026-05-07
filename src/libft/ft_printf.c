/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:35:37 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/04 23:43:49 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	select_type(char c, va_list args, int *output)
{
	if (c == 'c')
	{
		ft_putchar((char)va_arg(args, int), output);
	}
	else if (c == 's')
	{
		ft_putstr(va_arg(args, char *), output);
	}
	else if (c == 'p')
	{
		ft_putvoid(va_arg(args, void *), output);
	}
	else if (c == 'i' || c == 'd')
	{
		ft_putnbr(va_arg(args, int), output);
	}
	else if (c == 'u')
	{
		ft_putunsig(va_arg(args, unsigned int), output);
	}
	else if (c == 'x')
	{
		ft_puthex(va_arg(args, unsigned int), output);
	}
	else if (c == 'X')
	{
		ft_putupphex(va_arg(args, unsigned int), output);
	}
	else if (c == '%')
	{
		ft_putchar('%', output);
	}
}

int	ft_printf(char const *fmt, ...)
{
	va_list	args;
	int		i;
	int		output;

	va_start(args, fmt);
	i = 0;
	output = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] != '\0')
		{
			i++;
			select_type(fmt[i], args, &output);
		}
		else
		{
			ft_putchar(fmt[i], &output);
		}
		i++;
	}
	va_end(args);
	return (output);
}
