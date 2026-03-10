/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embostan <embostan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:34:12 by embostan          #+#    #+#             */
/*   Updated: 2026/03/09 13:39:33 by embostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(t_node *stack)
{
	int	max;
	int	bits;

	max = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
//en büyük sayının kaç bit olduğunu hesaplar