#include "push_swap.h"

void	swap_b(int *stack)
{
	swap_pos(stack, stack + 1);
	ft_printf("sb\n");
}

void	push_b(int *stack1, int *stack2, int *len1, int *len2)
{
	if (*len1 > 0)
	{
		push_pos(stack2, stack1, len2, len1);
		ft_printf("pb\n");	
	}
}

void	rotate_b(int *stack, int len)
{
	rotate_pos(stack, len);
	ft_printf("rb\n");
}

void	rotate_rr(int *stack_a, int *stack_b, int len_a, int len_b)
{
	rotate_pos(stack_a, len_a);
	rotate_pos(stack_b, len_b);
	ft_printf("rr\n");
}

void	reverse_rotate_b(int *stack, int len)
{
	reverse_rotate_pos(stack, len);
	ft_printf("rrb\n");
}