#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	*parse_args(int argc, char **argv, int check_buf)
{
	int	*arr;
	int	i;
	int	j;

	arr = malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (NULL);
	i = 1 + check_buf;
	while (i < (argc - 1))
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] <= '9' && argv[i][j] >= '0')
			|| (argv[i][j] == '-' || argv[i][j] == '+')))
			{
				write(1, "Error", 6);
				return (NULL);
			}
			j++;
		}
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (arr);
}

double	calculate_disorder(int *arr, int size, int check_buff)
{
	int		mistakes;
	int		total_pairs;
	int		i;
	int		j;

	if (size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0 + check_buff;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1;
			if (arr[i] > arr[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total_pairs);
}
