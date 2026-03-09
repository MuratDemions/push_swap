/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embostan <embostan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:06:50 by embostan          #+#    #+#             */
/*   Updated: 2026/03/05 15:20:34 by embostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    swap(t_node **stack)
{
    t_node	*first;
    t_node	*second;
    t_node	*tmp;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    tmp = second->next;
    *stack = second;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    first->next = tmp;
    if (tmp)
        tmp->prev = first;
}
void    sa(t_node **a)
{
    swap(*a);
    write(1, "sa\n", 3);
    count_move("sa");
}
void    sb(t_node **b)
{
    swap(*b);
    write(1, "sb\n", 3);
    count_move("sb");
}
void    ss(t_node **a, t_node **b)
{
    swap(*a);
    swap(*b);
    write(1, "ss\n", 3);
    count_move("ss");
}