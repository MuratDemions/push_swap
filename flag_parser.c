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
	index_stack(*a);
	if (strategy && ft_strcmp(strategy, "--simple") == 0)
		sort_simple(a, b);
	else if (strategy && ft_strcmp(strategy, "--medium") == 0)
		chunk_sort(a, b);
	else if (strategy && ft_strcmp(strategy, "--complex") == 0)
		radix_sort(a, b);
	else
		sort_adaptive(a, b);
}

static int	get_flag(int argc, char **argv)
{
	if (ft_strcmp(argv[1], "--bench") == 0 && argc > 2 && argv[2][0] == '-')
		return (2);
	if (ft_strcmp(argv[1], "--bench") == 0 || argv[1][0] == '-')
		return (1);
	return (0);
}

static double	init_stack(int argc, char **argv, t_node **a)
{
	int		*arr;
	double	disorder;
	int		i;

	arr = parse_args(argc, argv, get_flag(argc, argv));
	if (!arr)
		spt_error();
	i = 0;
	while (i < argc - 1 - get_flag(argc, argv))
		stack_add_back(a, stack_new(arr[i++]));
	disorder = calculate_disorder(arr, argc - 1 - get_flag(argc, argv));
	free(arr);
	return (disorder);
}

static void	run_bench(char **argv, t_node **a, t_node **b, double disorder)
{
	int	flag;

	flag = get_flag(0, argv);
	if (flag == 2)
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

void	bench_router(int argc, char **argv, t_node **a, t_node **b)
{
	double	disorder;

	if (argc < 2)
		return ;
	disorder = init_stack(argc, argv, a);
	if (ft_strcmp(argv[1], "--bench") == 0)
		run_bench(argv, a, b, disorder);
	else if (get_flag(argc, argv) == 1)
		router(argv[1], a, b);
}
