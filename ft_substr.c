/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musipit <musipit@student.42kocaeli.com.tr> #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-15 17:38:11 by musipit           #+#    #+#             */
/*   Updated: 2026-03-15 17:38:11 by musipit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	start_i;
	unsigned int	size;

	start_i = 0;
	size = 0;
	if (!s)
		return (NULL);
	while (start_i < start && s[start_i])
		start_i++;
	while (size < len && s[size + start_i])
		size++;
	substr = (char *)malloc(size + 1);
	if (!substr)
		return (NULL);
	substr[size] = '\0';
	while (size--)
		substr[size] = s[start_i + size];
	return (substr);
}
