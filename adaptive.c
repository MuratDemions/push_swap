/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-11 19:38:08 by musipit           #+#    #+#             */
/*   Updated: 2026-03-11 19:38:08 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	get_disorder(t_node *a, int size)
{
	int		*arr;
	t_node	*tmp;
	int		i;
	double	disorder;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	tmp = a;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	disorder = calculate_disorder(arr, size);
	free(arr);
	return (disorder);
}

void	sort_adaptive(t_node **a, t_node **b)
{
	int		size;
	double	disorder;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (size <= 10)
	{
		sort_simple(a, b);
		return ;
	}
	disorder = get_disorder(*a, size);
	if (disorder < 0.2)
		sort_simple(a, b);
	else if (disorder < 0.5)
		chunk_sort(a, b);
	else
		radix_sort(a, b);
}
