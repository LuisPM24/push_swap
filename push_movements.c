#include "push_swap.h"

void	sort_two(int *stack)
{
	if (stack[0] > stack[1])
		swap_a(stack);
}

void	sort_three(int *stack, int len)
{
	if (len != 3)
		return ;
	if (stack[0] > stack[1] && stack[1] > stack[2])
	{
		swap_a(stack);
		reverse_rotate_a(stack, len);
	}
	else if (stack[0] > stack[2] && stack[2] > stack[1])
		rotate_a(stack, len);
	else if (stack[1] > stack[0] && stack[0] > stack[2])
		reverse_rotate_a(stack, len);
	else if (stack[1] > stack[2] && stack[2] > stack[0])
		swap_a(stack);
	else if (stack[2] > stack[0] && stack[0] > stack[1])
	{
		swap_a(stack);
		rotate_a(stack, len);
	}
}

void	sort_selector(int *stack, int len)
{
	if (len < 2)
		return ;
	else if (len == 2)
		sort_two(stack);
	else if (len == 3)
		sort_three(stack, len);
	else if (len <= 5)
		sort_five(stack, len);
	else
		radix_sort(stack, len);
}