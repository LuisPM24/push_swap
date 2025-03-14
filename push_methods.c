#include "push_swap.h"

void	swap_pos(int *pos1, int *pos2)
{
	int	aux;

	aux = *pos1;
	*pos1 = *pos2;
	*pos2 = aux;
}

void	push_pos(int *stack1, int *stack2, int *len1, int *len2)
{
	int	count;

	if (*len2 == 0)
		return ;
	count = *len1;
	while (count > 0)
	{
		stack1[count] = stack1[count - 1];
		count--;
	}
	stack1[0] = stack2[0];
	count = 0;
	while (count < *len2 - 1)
	{
		stack2[count] = stack2[count + 1];
		count++;
	}
	(*len1)++;
	(*len2)--;
}

void	rotate_pos(int	*stack, int len)
{
	int	aux;
	int	count;

	if (!stack || len < 2)
		return ;
	count = 0;
	aux = stack[0];
	while(count < len - 1)
	{
		stack[count] = stack[count + 1];
		count++;
	}
	stack[len - 1] = aux;
}

void	reverse_rotate_pos(int *stack, int len)
{
	int	aux;
	int	count;

	if (!stack || len < 2)
		return ;
	count = len - 1;
	aux = stack[len - 1];
	while (count > 0)
	{
		stack[count] = stack[count - 1];
		count--;
	}
	stack[0] = aux;
}
