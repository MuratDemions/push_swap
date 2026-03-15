/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-15 12:04:01 by musipit           #+#    #+#             */
/*   Updated: 2026-03-15 12:04:01 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static void	sort_three(t_node **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top < mid && mid < bot)
		return ;
	else if (top < bot && bot < mid)
	{
		sa(a);
		ra(a);
	}
	else if (mid < top && top < bot)
		sa(a);
	else if (mid < bot && bot < top)
		ra(a);
	else if (bot < top && top < mid)
		rra(a);
	else if (bot < mid && mid < top)
	{
		sa(a);
		rra(a);
	}
}

static void	push_min_to_b(t_node **a, t_node **b)
{
	int	min_pos;
	int	size;
	int	i;

	size = stack_size(*a);
	min_pos = get_min_pos(*a);
	i = 0;
	if (min_pos <= size / 2)
	{
		while (i < min_pos)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < size - min_pos)
		{
			rra(a);
			i++;
		}
	}
	pb(a, b);
}

static void	sort_four_and_five(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		push_min_to_b(a, b);
		size--;
	}
	sort_three(a);
	while (stack_size(*b) > 0)
		pa(a, b);
}

void	sort_small(t_node **a, t_node **b, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_four_and_five(a, b);
}
