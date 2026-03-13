/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_short.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embostan <embostan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:35:29 by embostan          #+#    #+#             */
/*   Updated: 2026/03/12 15:23:44 by embostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static void	push_chunk(t_node **a, t_node **b, int chunk_size)
{
	int	chunk_min;
	int	chunk_max;
	int	total;
	int	checked;

	total = stack_size(*a);
	chunk_min = 0;
	chunk_max = chunk_size - 1;
	while (chunk_min < total)
	{
		checked = stack_size(*a);
		while (checked--)
		{
			if (!(*a))
				break ;
			if ((*a)->index >= chunk_min && (*a)->index <= chunk_max)
				pb(a, b);
			else
				ra(a);
		}
		chunk_min += chunk_size;
		chunk_max += chunk_size;
	}
}

static int	find_max_pos(t_node *b)
{
	int	max;
	int	pos;
	int	i;

	max = b->index;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			pos = i;
		}
		b = b->next;
		i++;
	}
	return (pos);
}

static void	pull_back(t_node **a, t_node **b)
{
	int	pos;
	int	size;
	int	rotations;

	while (*b)
	{
		size = stack_size(*b);
		pos = find_max_pos(*b);
		if (pos == 0)
			return ;
		else if (pos <= size / 2)
			while (pos--)
				rb(b);
		else
		{
			rotations = size - pos;
			while (rotations--)
				rrb(b);
		}
		pa(a, b);
	}
}

void	chunk_sort(t_node **a, t_node **b)
{
	int	chunk_size;

	chunk_size = int_sqrt(stack_size(*a));
	push_chunk(a, b, chunk_size);
	pull_back(a, b);
}
