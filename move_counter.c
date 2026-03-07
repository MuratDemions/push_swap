/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:32:00 by antigravity       ###   ########.fr       */
/*   Updated: 2026/03/07 15:32:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_counters(void)
{
	static int	counters[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	return (counters);
}

void	count_move(char *move)
{
	int	*counters;

	counters = get_counters();
	if (ft_strcmp(move, "pa") == 0)
		counters[0]++;
	else if (ft_strcmp(move, "pb") == 0)
		counters[1]++;
	else if (ft_strcmp(move, "sa") == 0)
		counters[2]++;
	else if (ft_strcmp(move, "sb") == 0)
		counters[3]++;
	else if (ft_strcmp(move, "ss") == 0)
		counters[4]++;
	else if (ft_strcmp(move, "ra") == 0)
		counters[5]++;
	else if (ft_strcmp(move, "rb") == 0)
		counters[6]++;
	else if (ft_strcmp(move, "rr") == 0)
		counters[7]++;
	else if (ft_strcmp(move, "rra") == 0)
		counters[8]++;
	else if (ft_strcmp(move, "rrb") == 0)
		counters[9]++;
	else if (ft_strcmp(move, "rrr") == 0)
		counters[10]++;
}

static void	print_count(char *label, int count)
{
	char	*num_str;

	if (count == 0)
		return ;
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd(label, 2);
	ft_putstr_fd(": ", 2);
	num_str = ft_itoa(count);
	ft_putstr_fd(num_str, 2);
	ft_putstr_fd("\n", 2);
	free(num_str);
}

void	print_move_counts(void)
{
	int	*c;

	c = get_counters();
	ft_putstr_fd("--- Move Counts ---\n", 2);
	print_count("pa", c[0]);
	print_count("pb", c[1]);
	print_count("sa", c[2]);
	print_count("sb", c[3]);
	print_count("ss", c[4]);
	print_count("ra", c[5]);
	print_count("rb", c[6]);
	print_count("rr", c[7]);
	print_count("rra", c[8]);
	print_count("rrb", c[9]);
	print_count("rrr", c[10]);
}
