/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:26:31 by scamlett          #+#    #+#             */
/*   Updated: 2026/04/23 21:38:35 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*lst;
	t_list	*new;

	lst = ft_lstnew("mundo");
	new = ft_lstnew("hola");
	ft_lstadd_front(&lst, new);
	printf("%s", (char *)lst->content);
	free(new);
	free(lst);
}
*/
