/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:15:20 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/04 16:03:08 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
    int				value;
    struct s_node	*next;
} 	t_node;

typedef struct s_stack
{
    int	*data;
    size_t	size;
} 	t_stack;
    
#endif