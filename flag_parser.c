/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-09 10:01:12 by musipit           #+#    #+#             */
/*   Updated: 2026/03/11 18:02:55 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	router(char *strategy, t_node **a, t_node **b)
{
	if (strategy && ft_strcmp(strategy, "--simple") == 0)
		sort_simple(a, b);
	else if (strategy && ft_strcmp(strategy, "--medium") == 0)
		sort_medium(a, b);
	else if (strategy && ft_strcmp(strategy, "--complex") == 0)
		radix_sort(a, b);
	else
		sort_adaptive(a, b);
}

void	bench_router(int argc, char **argv, t_node **a, t_node **b)
{
	int		*arr;
	double	disorder;

	arr = NULL;
	if (argc < 2)
		return ;
	br_helper(arr, argc, argv, a);
	disorder = calculate_disorder(arr, argc - 1 - flag_checker(argc, argv));
	free(arr);
	if (ft_strcmp(argv[1], "--bench") == 0)
	{
		if (flag_checker(argc, argv) == 2)
		{
			router(argv[2], a, b);
			bench_writer(writer_router(argv[2]), disorder);
		}
		else
		{
			router(NULL, a, b);
			bench_writer(writer_router(NULL), disorder);
		}
	}
	else if (flag_checker(argc, argv) == 1)
		router(argv[1], a, b);
}

void	br_helper(int *arr, int argc, char **argv, t_node **a)
{
	int	i;

	i = 0;
	arr = parse_args(argc, argv, flag_checker(argc, argv));
	if (!arr)
		spt_error();
	while (i < argc - 1 - flag_checker(argc, argv))
	{
		stack_add_back(a, stack_new(arr[i]));
		i++;
	}
}

int	flag_checker(int argc, char **argv)
{
	if (ft_strcmp(argv[1], "--bench") == 0)
	{
		if (argc > 2 && argv[2][0] == '-')
			return (2);
		else
			return (1);
	}
	else if (argv[1][0] == '-')
		return (1);
	return (0);
}

char	*writer_router(char *flag)
{
	if (!flag)
		return ("Adaptive / O(n log n)");
	if (ft_strcmp(flag, "--simple") == 0)
		return ("Simple / O(n^2)");
	if (ft_strcmp(flag, "--medium") == 0)
		return ("Medium / O(n√n)");
	if (ft_strcmp(flag, "--complex") == 0)
		return ("Complex / O(n log n)");
	return ("Adaptive / O(n log n)");
}
