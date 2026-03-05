/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embostan <embostan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:06:54 by embostan          #+#    #+#             */
/*   Updated: 2026/03/05 15:17:42 by embostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_node **a, t_node **b)
{
    t_node *tmp;
    
    if(!b || !*b)
        return;
    tmp = *b;
    *b = (*b)->next;
    if(*b)
        (*b)->prev = NULL;
    tmp->next = *a;
    tmp->prev = NULL;
    if(*a)
        (*a)->prev = tmp;
    *a = tmp;
    write(1, "pa\n", 3);
}
void    pb(t_node **a, t_node **b)
{
    t_node *tmp;
    
    if(!a || !*a)
        return;
    tmp = *a;
    *a = (*a)->next;
    if(*a)
        (*a)->prev = NULL;
    tmp->next = *b;
    tmp->prev = NULL;
    if(*b)
        (*b)->prev = tmp;
    *b = tmp;
    write(1, "pb\n", 3);
}