/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:20:31 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/12 13:00:38 by lupalomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// crear una funcion que crea una pila vacia (a o b) e iniliza la pila
// vacia a 0 = init
// devuelve stack a o stack b
static t_stack	*init_stack(char name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->name = name;
	stack->head = NULL;
	stack->size = 0;
	stack->flags = 0;
	stack->bench = 0;
	stack->disorder = 0;
	return (stack);
}

static t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	add_to_stack(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*last;
	int		index;

	node = new_node(value);
	if (!node)
		return ;
	if (!stack->head)
		stack->head = node;
	else
	{
		last = stack->head;
		while (last->next)
			last = last->next;
		index = last->index;
		last->next = node;
		node->index = index + 1;
	}
	stack->size++;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	if (argc < 2)
		return (0);
	stack_a = init_stack('a');
	stack_b = init_stack('b');
	args = parse_args(stack_a, argc, argv);
	if (!validate_args(args, stack_a))
	{
		fsin(argc, argv, args);
		print_error(stack_a);
	}
	start_algorithm(stack_a, stack_b);
	fsin(argc, argv, args);
	// print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
