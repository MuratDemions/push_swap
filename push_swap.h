/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embostan <embostan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:04:03 by embostan          #+#    #+#             */
/*   Updated: 2026/03/06 11:57:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);

void    pa(t_node **a, t_node **b);
void    pb(t_node **a, t_node **b);

void    ra(t_node **a);
void    ra(t_node **b);
void    rr(t_node **a, t_node **b);

void    rra(t_node **a);
void    rrb(t_node **b);
void    rrr(t_node **a, t_node **b);

t_node	*stack_new(int value);
void	stack_add_back(t_node **stack, t_node *new_node);
void	stack_clear(t_node **stack);
int		stack_size(t_node *stack);


double	calculate_disorder(int *arr, int size);

int		*parse_args(int argc, char **argv, int check_buf);
int		ft_atoi(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);

char	*ft_itoa(int n);
char	*writer_router(char *flag);

void	ft_putstr_fd(char *s, int fd);
void	print_move_counts(void);
void	count_move(char *move);
void	spt_error(void);
void	router(char *strategy, t_node **a, t_node **b);
void	bench_router(int argc, char **argv, t_node **a, t_node **b);

void	sort_simple(t_node **a, t_node **b);
void	sort_medium(t_node **a, t_node **b);
void	sort_complex(t_node **a, t_node **b);
void	sort_adaptive(t_node **a, t_node **b);

#endif