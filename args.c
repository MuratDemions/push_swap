/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-09 10:00:28 by musipit           #+#    #+#             */
/*   Updated: 2026-03-09 10:00:28 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_cheker(char *argv)
{
	long	num;

	num = ft_atol(argv);
	if (num < -2147483648 || num > 2147483647)
	{
		spt_error(NULL, NULL, NULL);
	}
	return (num);
}

static void	check_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				spt_error(arr, NULL, NULL);
			j++;
		}
		i++;
	}
}

int	*parse_args(int argc, char **argv, int check_buf)
{
	int	*arr;
	int	i;
	int	j;

	arr = malloc(sizeof(int) * (argc - 1 - check_buf));
	if (!arr)
		return (NULL);
	i = 1 + check_buf;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] <= '9' && argv[i][j] >= '0')
			|| (argv[i][j] == '-' || argv[i][j] == '+')))
				spt_error(arr, NULL, NULL);
			j++;
		}
		arr[i - 1 - check_buf] = int_cheker(argv[i]);
		i++;
	}
	if (argc - 1 - check_buf > 0)
		check_duplicates(arr, argc - 1 - check_buf);

	return (arr);
}
