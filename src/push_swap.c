/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:20:31 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/05 15:58:34 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*You must write a program named push_swap that takes as arguments:
- The stack a formatted as a list of integers (the first argument is the top of the stack).
- An optional strategy selector:
--simple Forces the use of your O(n2) algorithm.
--medium Forces the use of your O(n√n) algorithm.
--complex Forces the use of your O(n log n) algorithm.
--adaptive Forces the use of your adaptive algorithm based on disorder.
This is the default behavior if no selector is given.*/

// crear una funcion que crea una pila vacia (a o b) e iniliza la pila vacia a 0 = init
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
	stack->bench = 0;
	stack->strategy = 0;
	return (stack);
}

// init_node:

static t_node	*init_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	return (node);
}

// fill_stack:
static void	fill_stack(t_stack *stack, char **argv)
{
	t_node	*node;
	t_node	*position;
	int		count;

	count = 1;
	position = NULL;
	stack->head = NULL;
	while (argv[count])
	{
		node = malloc(sizeof(t_node));
		if (!node)
			return ;
		node->index = count - 1;
		node->value = ft_atoi(argv[count]);
		node->next = NULL;
		if (!stack->head)
			stack->head = node;
		else
			position->next = node;
		position = node;
		count++;
	}
	stack->size = count;
}

/*
ELIMINAR STDIO.H AL TERMINAR
*/
#include <stdio.h>
static void	print_stack(t_stack *stack)
{
	t_node *actual;

	actual = stack->head;
	printf("Stack %c\n", stack->name);
	printf("-------\n\n");
	while (actual)
	{
		printf("Index: %i; Value: %i;\n", actual->index, actual->value);
		actual = actual->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void)argc;
	stack_a = init_stack('a');
	stack_b = init_stack('b');
	fill_stack(stack_a, argv);
	print_stack(stack_a);
	return (0);
}