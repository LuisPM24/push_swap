#include "push_swap.h"

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap_pos(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_pos(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	quick_sort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

static void	copy_stack(int *src, int *dest, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	replace_with_indices(int *stack_a, int *tmp, int len_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < len_a)
	{
		j = 0;
		while (j < len_a)
		{
			if (stack_a[i] == tmp[j])
			{
				stack_a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static void	normalize_stack(int *stack_a, int len_a)
{
	int	*tmp;

	tmp = malloc(len_a * sizeof(int));
	if (!tmp)
		return;
	copy_stack(stack_a, tmp, len_a);
	quick_sort(tmp, 0, len_a - 1);
	replace_with_indices(stack_a, tmp, len_a);
	free(tmp);
}

static int	get_max_bits(int *stack_a, int size_a)
{
	int	max;
	int	max_bits;
	int	i;

	max = stack_a[0];
	i = 1;
	while (i < size_a)
	{
		if (stack_a[i] > max)
			max = stack_a[i];
		i++;
	}
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return max_bits;
}

static void	radix_sort_phase(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	count;
	int	j;
	int	i;
	int	max_bits;

	i = 0;
	max_bits = get_max_bits(stack_a, *size_a);
	while (i < max_bits)
	{
		count = *size_a;
		j = 0;
		while (j < count)
		{
			if (((stack_a[0] >> i) & 1) == 0)
				push_b(stack_a, stack_b, size_a, size_b);
			else
				rotate_a(stack_a, *size_a);
			j++;
		}
		while (*size_b > 0)
			push_a(stack_a, stack_b, size_a, size_b);
		i++;
	}
}

void	radix_sort(int *stack_a, int *stack_b, int len_a, int *len_b)
{
	int	size_a;
	int	size_b;

	normalize_stack(stack_a, len_a);
	size_a = len_a;
	size_b = 0;
	radix_sort_phase(stack_a, stack_b, &size_a, &size_b);
	*len_b = size_b;
}
