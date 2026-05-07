/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:15:20 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/05 15:02:21 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				index;
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	char			name;
	t_node			*head;
	unsigned int	size;
	int				bench;
	int				strategy;
}					t_stack;

// utils.c
t_node				*last_node(t_node *lst);

// swap.c
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);
// push.c
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
// rotate.c
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
// reverse_rotate.c
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);

#endif