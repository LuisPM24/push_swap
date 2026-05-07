/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamlett <scamlett@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:26:51 by scamlett          #+#    #+#             */
/*   Updated: 2026/05/05 10:58:05 by scamlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Python code in subject has been translated to C.
// The array is passed as a pointer + size,
// since C doesn't know the length of the array at runtime.
// The return type is float so the division doesn't truncate.
float	compute_disorder(int *a, int size)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (a[i] > a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((float)mistakes / total_pairs);
}
