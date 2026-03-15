/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-15 17:38:11 by musipit           #+#    #+#             */
/*   Updated: 2026-03-15 17:38:11 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_free(char **list)
{
	size_t	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		list[i] = NULL;
		i++;
	}
	free(list);
	return (NULL);
}

static size_t	w_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static size_t	w_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			s += w_len(s, c);
			count++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	i;

	if (!s)
		return (NULL);
	list = (char **)malloc((w_count(s, c) + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			list[i] = ft_substr(s, 0, w_len(s, c));
			if (!list[i])
				return (ft_free(list));
			s += w_len(s, c);
			i++;
		}
	}
	list[i] = NULL;
	return (list);
}
