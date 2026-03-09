/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-09 10:20:29 by musipit           #+#    #+#             */
/*   Updated: 2026-03-09 10:20:29 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	load_stack(t_node **a, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack_add_back(a, stack_new(arr[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		*arr;
	int		size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (argv[1][0] == '-')
		bench_router(argc, argv, &a, &b);
	else
	{
		arr = parse_args(argc, argv, 0);
		if (!arr)
			spt_error();
		size = argc - 1;
		load_stack(&a, arr, size);
		free(arr);
		sort_adaptive(&a, &b);
	}
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
