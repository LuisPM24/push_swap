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
static t_stack	*init_stack(char name, char **argv, int *position)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->name = name;
	stack->head = NULL;
	stack->size = 0;
	if (name == 'a')
		stack_parser(stack, argv, position);
	stack->disorder = 0;
	return (stack);
}

static void	fill_stack(t_stack *stack, char **argv, int pos)
{
	t_node	*node;
	t_node	*position;
	int		count;

	count = 0;
	position = NULL;
	stack->head = NULL;
	while (argv[pos + count])
	{
		node = malloc(sizeof(t_node));
		if (!node)
			return ;
		node->index = count;
		node->value = ft_atoi(argv[pos + count]);
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		position;

	if (argc <= 1)
		return (0);
	position = 1;
	if (search_errors(argv))
		print_error(NULL);
	stack_a = init_stack('a', argv, &position);
	stack_b = init_stack('b', argv, &position);
	fill_stack(stack_a, argv, position);
	start_algorithm(stack_a, stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
