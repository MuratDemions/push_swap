/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-12 12:16:04 by musipit           #+#    #+#             */
/*   Updated: 2026-03-12 12:16:04 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	execute_op(char *op, t_node **a, t_node **b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(op, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(op, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(op, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(a, b);
	else
		spt_error();
}

static int	get_line(char *buf)
{
	int		i;
	ssize_t	r;
	char	c;

	i = 0;
	while (i < 9)
	{
		r = read(0, &c, 1);
		if (r <= 0)
			return (i);
		buf[i++] = c;
		if (c == '\n')
			break ;
	}
	buf[i] = '\0';
	return (i);
}

int	main(int argc, char **argv)
{
	t_node	*a = NULL;
	t_node	*b = NULL;
	int		*arr;
	int		i;
	char	buf[10];

	if (argc < 2)
		return (0);
	arr = parse_args(argc, argv, 0);
	if (!arr)
		spt_error();
	i = 0;
	while (i < argc - 1)
		stack_add_back(&a, stack_new(arr[i++]));
	free(arr);
	while (get_line(buf))
		execute_op(buf, &a, &b);
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
