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
		chunk_sort(a, b);
    else if (strategy && ft_strcmp(strategy, "--complex") == 0)
		radix_sort(a, b);
	else
		sort_adaptive(a, b);
}

void	bench_router(int argc, char **argv, t_node **a, t_node **b)
{
	int		*arr;
	double	disorder;
	int		flag_detecter;
	int		i;

	i = 0;
	flag_detecter = 0;
	if (argc < 2)
		return ;
	if (ft_strcmp(argv[1], "--bench") == 0)
	{
		if (argc > 2 && argv[2][0] == '-')
			flag_detecter = 2;
		else
			flag_detecter = 1;
	}
	else if (argv[1][0] == '-')
		flag_detecter = 1;
	arr = parse_args(argc, argv, flag_detecter);
	if (!arr)
		spt_error();
	while (i < argc - 1 - flag_detecter)
	{
		stack_add_back(a, stack_new(arr[i]));
		i++;
	}
	disorder = calculate_disorder(arr, argc - 1 - flag_detecter);
	free(arr);
	if (ft_strcmp(argv[1], "--bench") == 0)
	{
		if (flag_detecter == 2)
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
	else if (flag_detecter == 1)
		router(argv[1], a, b);
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