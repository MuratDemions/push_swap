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

int	get_min_pos(t_node *a)
{
	int	min;
	int	pos;
	int	i;

	min = a->value;
	pos = 0;
	i = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		free(split[i++]);
	free(split);
}

void	validate_and_fill(char **split, int *arr, int count)
{
	int		i;
	long	num;

	i = -1;
	while (++i < count)
	{
		num = ft_atol(split[i]);
		if (num < -2147483648 || num > 2147483647)
		{
			free_split(split);
			free(arr);
			spt_error(NULL, NULL, NULL);
		}
		arr[i] = (int)num;
	}
}

void	duplicates_check(int *arr, int count, char **split)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
			{
				free_split(split);
				free(arr);
				spt_error(NULL, NULL, NULL);
			}
			j++;
		}
		i++;
	}
}
