#include "push_swap.h"

static int	get_min_pos(t_node *a)
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

void	sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_node **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->index;
	mid = (*a)->next->index;
	bot = (*a)->next->next->index;
	if (top == 0 && mid == 1 && bot == 2)
		return ;
	else if (top == 0 && mid == 2 && bot == 1)
		rra(a);
	else if (top == 1 && mid == 0 && bot == 2)
		sa(a);
	else if (top == 1 && mid == 2 && bot == 0)
		ra(a);
	else if (top == 2 && mid == 0 && bot == 1)
	{
		sa(a);
		ra(a);
	}
	else if (top == 2 && mid == 1 && bot == 0)
	{
		sa(a);
		rra(a);
	}
}

void	sort_four_and_five(t_node **a, t_node **b)
{
	int	min_pos_val;
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		min_pos_val = get_min_pos(*a);
		if (min_pos_val <= size / 2)
			while (min_pos_val-- > 0)
				ra(a);
		else
			while (min_pos_val++ < size)
				rra(a);
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (stack_size(*b) > 0)
		pa(a, b);
}

void	sort_small(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 1)
		return ;
	else if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_four_and_five(a, b);
}
