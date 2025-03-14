#include "push_swap.h"

static int	count_str(char **str_stack)
{
	int	count;

	count = 0;
	if (!str_stack)
		return (0);
	while (str_stack[count])
		count++;
	return (count);
}

static int	*str_insert_numbs(char **str_stack, int len)
{
	int	*num_aux;
	int	count;

	count = 0;
	num_aux = malloc(sizeof(int) * len);
	if (!num_aux)
	{
		ft_printf("Error\n");
		free_split(str_stack);
		return (NULL);
	}
	while (count < len)
	{
		num_aux[count] = ft_atoi(str_stack[count]);
		count++;
	}
	if (has_duplicates(num_aux, len))
	{
		ft_printf("Error\n");
		free(num_aux);
		free_split(str_stack);
		return (NULL);
	}
	return (num_aux);
}

static int	*int_insert_numbs(char **str_stack, int len)
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
	while (count <= len)
	{
		num_aux[count - 1] = ft_atoi(str_stack[count]);
		count++;
	}
	if (has_duplicates(num_aux, len))
	{
		ft_printf("Error\n");
		free(num_aux);
		return (NULL);
	}
	return (num_aux);
}

static void	free_split(char **split_nums)
{
	int	count;

	if (!split_nums)
		return ;
	count = 0;
	while (split_nums[count])
	{
		free(split_nums[count]);
		count++;
	}
	free(split_nums);
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
		if (!split_nums)
			return (1);
		count = count_str(split_nums);
		if (!validate_input(split_nums, count))
		{
			free_split(split_nums);
			return (1);
		}
		stack = str_insert_numbs(split_nums, count);
		free_split(split_nums);
	}
	else if (argc > 2)
	{
		count = argc - 1;
		if (!validate_input(argv + 1, count))
			return (1);
		stack = int_insert_numbs(argv, count);
	}
	if (!stack)
		return (1);
	sort_selector(stack, count);
	free(stack);
	return (0);
}
