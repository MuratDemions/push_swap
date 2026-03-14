/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_and_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-09 10:02:15 by musipit           #+#    #+#             */
/*   Updated: 2026-03-09 10:02:15 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	spt_error(int *arr, t_node **a, t_node **b)
{
	ft_putstr_fd("Error\n", 2);
	if (a)
		stack_clear(a);
	if (arr)
		free(arr);
	if (b)
		stack_clear(b);
	exit(1);
}
