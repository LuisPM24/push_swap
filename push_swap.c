#include "push_swap.h"

int	count_str(char **str_stack)
{
	int	count;

	count = 0;
	if (!str_stack)
		return (0);
	while (str_stack[count])
		count++;
	return (count);
}

int	*str_insert_numbs(char **str_stack, int len)
{
	int	*num_aux;
	int	count;

	count = 0;
	num_aux = malloc(sizeof(int) * len);
	if (!num_aux)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	while (str_stack[count])
	{
		num_aux[count] = ft_atoi(str_stack[count]);
		count++;
	}
	return (num_aux);
}

int	*int_insert_numbs(char **str_stack, int len)
{
	int	*num_aux;
	int	count;

	count = 1;
	num_aux = malloc(sizeof(int) * len);
	if (!num_aux)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	while (str_stack[count])
	{
		num_aux[count - 1] = ft_atoi(str_stack[count]);
		count++;
	}
	return (num_aux);
}

int	main(int argc, char **argv)
{
	char	**split_nums;
	int		*stack;
	int		count;

	split_nums = NULL;
	stack = NULL;
	count = 0;
	if (argc == 2)
	{
		split_nums = ft_split(argv[1], ' ');
		count = count_str(split_nums);
		stack = str_insert_numbs(split_nums, count);
	}
	else if (argc > 2)
		stack = int_insert_numbs(argv, (argc - 1));
	if (!stack)
		return (1);
		
	return (0);
}