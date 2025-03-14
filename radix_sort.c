#include "push_swap.h"

static void	bubble_sort(int *array, int len)
{
	int	i;
	int	j;
	int	temp;
	int	is_swapped;

	i = 0;
	while (i < len - 1)
	{
		is_swapped = 0;
		j = 0;
		while (j < len - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				is_swapped = 1;
			}
			j++;
		}
		if (!is_swapped)
			break ;
		i++;
	}
}


static int *copy_and_sort(int *stack, int len)
{
    int *sorted;
    int i;

    sorted = malloc(len * sizeof(int));
    if (!sorted)
        return NULL;

    i = 0;
    while (i < len)
    {
        sorted[i] = stack[i];
        i++;
    }

    bubble_sort(sorted, len);

    return sorted;
}

static int	*normalize(int *stack, int *sorted, int len)
{
	int	*normalized;
	int	i;
	int	j;

	normalized = malloc(len * sizeof(int));
	if (!normalized)
		return (NULL);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (stack[i] == sorted[j])
			{
				normalized[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (normalized);
}

void	radix_sort(int *stack_a, int *stack_b, int len_a, int *len_b)
{
	int	max_bits;
	int	i;
	int	j;
	int	num;

	max_bits = 0;
	while ((len_a - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < len_a)
		{
			num = stack_a[0];
			if (((num >> i) & 1) == 1)
				rotate_a(stack_a, len_a);
			else
				push_b(stack_a, stack_b, &len_a, len_b);
			j++;
		}
		while (*len_b > 0)
			push_a(stack_a, stack_b, &len_a, len_b);
		i++;
	}
}
