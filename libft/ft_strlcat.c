/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:15:18 by scamlett          #+#    #+#             */
/*   Updated: 2026/04/24 12:33:24 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	source_len;

	dest_len = 0;
	source_len = ft_strlen(src);
	while (dst[dest_len] && dest_len < size)
		dest_len++;
	if (dest_len == size)
		return (size + source_len);
	i = 0;
	while (src[i] && (dest_len + i + 1) < size)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + source_len);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dst[12] = "Hola";
	size_t	len;

	len = ft_strlcat(dst, "42", sizeof(dst));
	printf("dst: %s | len: %zu", dst, len);
	return (0);
}
*/
