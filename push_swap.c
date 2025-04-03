/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:02:22 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/02 18:12:53 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *stack, char name)
{
	stack->top = NULL;
	stack->size = 0;
	stack->name = name;
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->cost = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_to_stack(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*last;

	node = new_node(value);
	if (!node)
		return ;
	if (!stack->top)
		stack->top = node;
	else
	{
		last = stack->top;
		while (last->next)
			last = last->next;
		last->next = node;
		node->prev = last;
	}
	stack->size++;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**args;

	if (argc < 2)
		return (0);
	init_stack(&a, 'a');
	init_stack(&b, 'b');
	args = get_args(argc, argv);
	if (!validate_args(args, &a))
	{
		ft_putstr_fd("Error\n", 2);
		fsin(argc, args);
		free_stack(&a);
		free_stack(&b);
		return (1);
	}
	method_selector(&a, &b);
	fsin(argc, args);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
