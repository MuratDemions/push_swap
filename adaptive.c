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

void	sort_adaptive(t_node **a, t_node **b)
{
	int		size;
	int		*arr;
	double	disorder;
	t_node	*tmp;
	int		i;

	size = stack_size(*a);
	if (size >= 1 && size <= 5)
	{
		sort_small(a, b, size);
		return ;
	}
	arr = (int *)malloc(sizeof(int) * size);
	tmp = *a;
	i = 0;
	while (i++ < size)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
	}
	disorder = calculate_disorder(arr, size);
	adaptive_disorder_part(a, b, disorder);
	free(arr);
}

void	adaptive_disorder_part(t_node **a, t_node **b, double disorder)
{
	if (disorder < 0.2)
		sort_simple(a, b);
	else if (disorder < 0.5)
		chunk_sort(a, b);
	else if (disorder >= 0.5)
		radix_sort(a, b);
	return ;
}
