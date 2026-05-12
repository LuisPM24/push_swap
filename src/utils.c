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

int	is_flag(char *str)
{
	if (ft_strcmp(str, "--bench") == 0
		|| ft_strcmp(str, "--adaptative") == 0
		|| ft_strcmp(str, "--simple") == 0
		|| ft_strcmp(str, "--medium") == 0
		|| ft_strcmp(str, "--complex") == 0)
		return (1);
	return (0);
}

void	print_error(t_stack *stack)
{
	ft_printf("Error\n");
	free_stack(stack);
	exit(EXIT_FAILURE);
}

void	print_stack(t_stack *stack)
{
	t_node	*actual;

	actual = stack->head;
	ft_printf("Stack %c\n", stack->name);
	ft_printf("-------\n\n");
	while (actual)
	{
		ft_printf("Index: %i; Value: %i;\n", actual->index, actual->value);
		actual = actual->next;
	}
	ft_printf("\n");
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next_node;

	if (!stack)
		return ;
	node = stack->head;
	while (node)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
	free(stack);
}
