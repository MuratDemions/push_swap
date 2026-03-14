/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-11 19:38:08 by musipit           #+#    #+#             */
/*   Updated: 2026-03-11 19:38:08 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_node **a, t_node **b)
{
	int		size;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	if (size <= 3)
	{
		sort_small(a, b);
		return ;
	}
	if (size <= 5)
	{
		sort_small(a, b);
		return ;
	}
	sort_simple(a, b);
}
