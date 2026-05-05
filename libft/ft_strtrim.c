/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:28:55 by scamlett          #+#    #+#             */
/*   Updated: 2026/04/23 15:57:44 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_isinset(s1[start], set))
		start++;
	while (end > start && ft_isinset(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
/*
#include <stdio.h>

int	main(void)
{
	char	*trim;

	trim = ft_strtrim("--hola--", "-");
	if (!trim)
		return (1);
	printf("%s\n", trim);
	free(trim);
	return (0);
}
*/
