/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-11 20:03:22 by musipit           #+#    #+#             */
/*   Updated: 2026-03-11 20:03:22 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_pos(t_node *a)
{
	int	min;
	int	pos;
	int	i;

	min = a->value;
	pos = 0;
	i = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

void	sort_simple(t_node **a, t_node **b)
{
	int	size;
	int	pos;

	size = stack_size(*a);
	while (size > 0)
	{
		pos = min_pos(*a);
		if (pos <= size / 2)
			while (pos--)
				ra(a);
		else
			while (pos++ < size)
				rra(a);
		pb(a, b);
		size--;
	}
	while (*b)
		pa(a, b);
}
