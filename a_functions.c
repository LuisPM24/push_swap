#include "push_swap.h"

void	swap_a(int *stack)
{
	swap_pos(stack, stack + 1);
	ft_printf("sa\n");
}

void	push_a(int *stack1, int *stack2, int *len1, int *len2)
{
	if (*len2 > 0)
	{
		push_pos(stack1, stack2, len1, len2);
		ft_printf("pa\n");	
	}
}

void	rotate_a(int *stack, int len)
{
	rotate_pos(stack, len);
	ft_printf("ra\n");
}

void	reverse_rotate_a(int *stack, int len)
{
	reverse_rotate_pos(stack, len);
	ft_printf("rra\n");
}

void	reverse_rotate_rr(int *stack_a, int *stack_b, int len_a, int len_b)
{
	reverse_rotate_pos(stack_a, len_a);
	reverse_rotate_pos(stack_b, len_b);
	ft_printf("rrr\n");
}
