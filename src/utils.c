/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:36:47 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/05 12:40:04 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
last_node: walks to the end of a linked list and returns the last node.
Needed by ra, rb and rr to append the detached head to the tail.
Same implementation as ft_lstlast.c in libft, but for t_node instead of t_list.
*/
t_node	*last_node(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
