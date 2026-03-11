/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embostan <embostan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:06:57 by embostan          #+#    #+#             */
/*   Updated: 2026/03/11 18:13:40 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	tmp = last;
	last = last->prev;
	last->next = NULL;
	last = tmp;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	*stack = last;
}

void	rra(t_node **a)
{
	r_rotate(a);
	write(1, "rra\n", 4);
	count_move("rra");
}

void	rrb(t_node **b)
{
	r_rotate(b);
	write(1, "rrb\n", 4);
	count_move("rrb");
}

void	rrr(t_node **a, t_node **b)
{
	r_rotate(a);
	r_rotate(b);
	write(1, "rrr\n", 4);
	count_move("rrr");
}
