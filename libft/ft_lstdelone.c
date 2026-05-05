/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:49:14 by scamlett          #+#    #+#             */
/*   Updated: 2026/04/23 21:38:45 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>

void	del(void *content)
{
	if (content)
		printf("Deleting: %s", (char *)content);
		free(content);
}

int	main(void)
{
	t_list *node;

	node = ft_lstnew(ft_strdup("hello"));
	ft_lstdelone(node, del);
}*/