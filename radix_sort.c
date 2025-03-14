#include "push_swap.h"

static int	compare_int(const void *a, const void *b)
{
	int	ia = *(const int *)a;
	int	ib = *(const int *)b;
	return (ia - ib);
}

void	radix_sort(int *stack_a, int *stack_b, int len_a, int *len_b)
{
	int	*tmp;
	int	i, j;
	int	size_a;
	int	size_b;
	int	max;
	int	max_bits;
	int	count;

	/* FASE DE NORMALIZACIÓN:
	   Se crea una copia del stack para obtener el orden relativo (ranking) de cada número.
	   Esto es especialmente útil si los números incluyen negativos. */
	tmp = malloc(len_a * sizeof(int));
	if (!tmp)
		return;
	i = 0;
	while (i < len_a)
	{
		tmp[i] = stack_a[i];
		i++;
	}
	// Ordenamos la copia con qsort.
	qsort(tmp, len_a, sizeof(int), compare_int);
	// Reemplazamos cada valor por su índice (su ranking).
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
	free(tmp);

	/* FASE DE RADIX SORT:
	   Usamos el método bit a bit para ordenar. */
	size_a = len_a;
	size_b = 0;
	// Hallamos el valor máximo para saber cuántos bits necesitamos.
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

	i = 0;
	while (i < max_bits)
	{
		count = size_a;
		j = 0;
		while (j < count)
		{
			// Revisamos el bit i del primer elemento de stack_a.
			if (((stack_a[0] >> i) & 1) == 0)
				push_b(stack_a, stack_b, &size_a, &size_b); // pb: empuja a stack_b.
			else
				rotate_a(stack_a, size_a); // ra: rota stack_a.
			j++;
		}
		// Una vez terminada la iteración, se reinyectan todos los elementos desde stack_b a stack_a.
		while (size_b > 0)
			push_a(stack_a, stack_b, &size_a, &size_b); // pa: empuja de vuelta a stack_a.
		i++;
	}
	// Actualizamos len_b (debe quedar en 0).
	*len_b = size_b;
}