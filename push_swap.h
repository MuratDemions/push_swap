/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embostan <embostan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:04:03 by embostan          #+#    #+#             */
/*   Updated: 2026/03/05 15:22:04 by embostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);

void    pa(t_node **a, t_node **b);
void    pb(t_node **a, t_node **b);

void    ra(t_node **a);
void    ra(t_node **b);
void    rr(t_node **a, t_node **b);

void    rra(t_node **a);
void    rrb(t_node **b);
void    rrr(t_node **a, t_node **b);

#endif