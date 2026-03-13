/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_helperone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-09 10:01:21 by musipit           #+#    #+#             */
/*   Updated: 2026-03-09 10:01:21 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

long	ft_atol(const char *nptr)
{
	long	sum;
	int		i;
	int		sign;

	i = 0;
	sum = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = (sum * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * sum);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static size_t	intlen(int n)
{
	long	nb;
	size_t	len;

	len = 0;
	nb = n;
	if (nb <= 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*str;

	nb = n;
	len = intlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	str[len] = '\0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

void	bench_writer(char *strategy, double disorder)
{
	char	*dis_str;

	ft_putstr_fd("[bench] disorder:	", 2);
	dis_str = ft_itoa((int)(disorder * 100));
	ft_putstr_fd(dis_str, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy:	", 2);
	ft_putstr_fd(strategy, 2);
	ft_putstr_fd("\n", 2);
	print_move_counts();
	free(dis_str);
}
