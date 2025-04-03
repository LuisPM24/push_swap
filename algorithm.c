/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:03:43 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/03 18:21:49 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_stack *a, t_stack *b)
{
	t_node	*winner;

	winner = NULL;
	push_with_mean(a, b);
	sort_five(a, b);
	while (b->size != 0)
	{
		assign_all_bf(a, b);
		assign_all_costs(a, b);
		winner = select_winner(b);
		do_winner_movement(winner->best_friend, a);
		do_winner_movement(winner, b);
		push_a(a, b);
		reset_bfs_and_cost(b);
	}
	final_rotation(a);
}

void	method_selector(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		algorithm(a, b);
}
