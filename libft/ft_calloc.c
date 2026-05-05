/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:08:43 by scamlett          #+#    #+#             */
/*   Updated: 2026/04/27 21:47:16 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
It is necessary to check for integer overflows in (count * size)
before calling malloc. If the result overflows, malloc may allocate less memory
than expected, leading to buffer overflows or memory leaks. This implementation
uses (size_t)-1 to represent the maximum value of size_t for the check.
This ensures that ft_calloc behaves safely and avoids undefined behavior.
*/
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (size != 0 && count > ((size_t)-1) / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/*#include <stdio.h>

int	main(void)
{
	int	*arr;
	int	i;

	arr = ft_calloc(3, 5);
	printf("%p\n", arr);
	i = 0;
	while (i < 5)
	{
		printf("%d ", arr[i]);
		i++;
	}
	free(arr);
	return (0);
}*/
