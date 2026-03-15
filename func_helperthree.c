/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_helperthree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-15 20:19:03 by musipit           #+#    #+#             */
/*   Updated: 2026-03-15 20:19:03 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_writer_help(char *strategy)
{
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy:	", 2);
	ft_putstr_fd(strategy, 2);
	ft_putstr_fd("\n", 2);
}
