#include "push_swap.h"

void sort_two(int *stack)
{
	if (stack[0] > stack[1])
		swap_a(stack);
}

void sort_three(int *stack, int len)
{
	if (len != 3)
		return;
	if (stack[0] < stack[1] && stack[1] < stack[2])
		return;
	if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] < stack[2])
		swap_a(stack);
	else if (stack[0] > stack[1] && stack[1] > stack[2])
	{
		swap_a(stack);
		reverse_rotate_a(stack, len);
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] > stack[2])
		rotate_a(stack, len);
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] < stack[2])
	{
		swap_a(stack);
		rotate_a(stack, len);
	}
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] > stack[2])
		reverse_rotate_a(stack, len);
}

void sort_selector(int *stack, int len)
{
	int *stack_b;
	int len_b;

	if (len < 2)
		return;
	else if (len == 2)
		sort_two(stack);
	else if (len == 3)
		sort_three(stack, len);
	else
	{
		stack_b = malloc(len * sizeof(int));
		if (!stack_b)
			return;
		len_b = 0;
		radix_sort(stack, stack_b, len, &len_b);
		free(stack_b);
	}
}
