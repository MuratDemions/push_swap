/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embostan <embostan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:06:47 by embostan          #+#    #+#             */
/*   Updated: 2026/03/05 15:21:03 by embostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_node **stack)
{
    t_node	*first;
    t_node	*last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    last = *stack;
    while (last->next)
        last = last->next;
    *stack = first->next;
    (*stack)->prev = NULL;
    last->next = first;
    first->prev = last;
    first->next = NULL;
}
void    ra(t_node **a)
{
    rotate(*a);
    write(1, "ra\n", 3);
}
void    ra(t_node **b)
{
    rotate(*b);
    write(1, "rb\n", 3);
}
void    rr(t_node **a, t_node **b)
{
    rotate(*a);
    rotate(*b);
    write(1, "rr\n", 3);
}