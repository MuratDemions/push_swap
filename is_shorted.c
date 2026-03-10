/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embostan <embostan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:32:18 by embostan          #+#    #+#             */
/*   Updated: 2026/03/09 14:19:51 by embostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
//stack küçükten büyüğe sıralı mı
