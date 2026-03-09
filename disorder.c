/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-09 10:00:40 by musipit           #+#    #+#             */
/*   Updated: 2026-03-09 10:00:40 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

double	calculate_disorder(int *arr, int size)
{
	int		mistakes;
	int		total_pairs;
	int		i;
	int		j;

	if (size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1;
			if (arr[i] > arr[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total_pairs);
}
