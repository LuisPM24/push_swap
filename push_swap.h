#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

//Push validations
int		is_valid_number(char *str);
int		has_duplicates(int *stack, int len);
int		validate_input(char **nums, int count);

//Push Swap utils
void	sort_selector(int *stack, int len);
void	sort_two(int *stack, int len);
void	sort_three(int *stack, int len);
void	radix_sort(int *stack_a, int *stack_b, int len_a, int *len_b);

//Push methods
void	swap_pos(int *pos1, int *pos2);
void	push_pos(int *stack1, int *stack2, int *len1, int *len2);
void	rotate_pos(int	*stack, int len);
void	reverse_rotate_pos(int *stack, int len);

//Push movements
void	swap_a(int *stack);
void	swap_b(int *stack);
void	push_a(int *stack1, int *stack2, int *len1, int *len2);
void	push_b(int *stack1, int *stack2, int *len1, int *len2);
void	rotate_a(int *stack, int len);
void	rotate_b(int *stack, int len);
void	rotate_rr(int *stack_a, int *stack_b, int len_a, int len_b);
void	reverse_rotate_a(int *stack, int len);
void	reverse_rotate_b(int *stack, int len);
void	reverse_rotate_rr(int *stack_a, int *stack_b, int len_a, int len_b);


#endif