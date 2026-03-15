/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embostan <embostan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:34:56 by embostan          #+#    #+#             */
/*   Updated: 2026/03/11 18:20:42 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_push_bits(t_node **a, t_node **b, int i, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if ((((*a)->index >> i) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		j++;
	}
}

void	radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	i;
	int	bits;

	index_stack(*a);
	size = stack_size(*a);
	bits = max_bits(*a);
	if (size >= 1 && size <= 5)
	{
		sort_small(a, b, size);
		return ;
	}
	i = 0;
	while (i < bits)
	{
		radix_push_bits(a, b, i, size);
		while (*b)
			pa(a, b);
		i++;
	}
}
