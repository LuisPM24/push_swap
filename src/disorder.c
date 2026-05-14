/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:26:51 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/12 13:07:05 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Python code in subject has been translated to C.
// The array is passed as a pointer + size,
// since C doesn't know the length of the array at runtime.
// The return type is float so the division doesn't truncate.
/*
float	compute_disorder(int *a, int size)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (a[i] > a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((float)mistakes / total_pairs);
}
*/

float	disorder(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;
	float	mistakes;
	float	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	if (!stack || !stack->head)
		return (0);
	node1 = stack->head;
	while (node1)
	{
		node2 = node1->next;
		while (node2)
		{
			total_pairs++;
			if (node1->value > node2->value)
				mistakes++;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}
