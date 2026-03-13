/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_helpertwo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-13 22:01:57 by musipit           #+#    #+#             */
/*   Updated: 2026-03-13 22:01:57 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*writer_router(char *flag)
{
	if (!flag)
		return ("Adaptive / O(n log n)");
	if (ft_strcmp(flag, "--simple") == 0)
		return ("Simple / O(n^2)");
	if (ft_strcmp(flag, "--medium") == 0)
		return ("Medium / O(n√n)");
	if (ft_strcmp(flag, "--complex") == 0)
		return ("Complex / O(n log n)");
	return ("Adaptive / O(n log n)");
}
