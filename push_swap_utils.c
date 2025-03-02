#include "push_swap.h"

void	swap_pos(char **pos1, char **pos2)
{
	int	*aux;

	aux = *pos1;
	*pos1 = *pos2;
	*pos2 = aux;
}

void	push_pos(char **pos1, char **pos2)
{
	if (!(*pos2))
		return ;
	*pos1 = *pos2;
	*pos2 = NULL;
}

void	rotate_pos(int	*stack, int len)
{
	int	aux;
	int	count;

	aux = 0;
	count = 0;
	if (!stack || len < 2)
		return ;
	aux = stack[count];
	while(count < len - 1)
	{
		stack[count] = stack[count + 1];
		count++;
	}
	stack[count] = aux;
}

void	reverse_rotate_pos(int *stack, int len)
{
	int	aux;
	int	count;

	aux = 0;
	len = 0;
	if (!stack || len < 2)
		return ;
	count = len - 1;
	aux = stack[count];
	while (count > 0)
	{
		stack[count] = stack[count - 1];
		count--;
	}
	stack[count] = aux;
}
