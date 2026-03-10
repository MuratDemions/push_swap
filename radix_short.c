/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_short.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: embostan <embostan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:34:56 by embostan          #+#    #+#             */
/*   Updated: 2026/03/09 15:32:01 by embostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	i;
	int	j;
	int	bits;

	size = stack_size(*a);
	bits = max_bits(*a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

// Basit stack yazdırma fonksiyonu
void print_stack(t_node *stack)
{
    while (stack)
    {
        printf("%d(index:%d) -> ", stack->value, stack->index);
        stack = stack->next;
    }
    printf("NULL\n");
}

// Node oluştur
t_node *create_node(int value, int index)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return NULL;
    new_node->value = value;
    new_node->index = index;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Stack'e sona ekleme
void append_node(t_node **stack, t_node *new_node)
{
    t_node *tmp;

    if (!*stack)
        *stack = new_node;
    else
    {
        tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
        new_node->prev = tmp;
    }
}

int main(void)
{
    t_node *a = NULL;
    t_node *b = NULL;

    int values[6] = {803, 72, 154, 85, 4, 263};
    for (int i = 0; i < 6; i++)
        append_node(&a, create_node(values[i], 0)); // index başlangıçta 0

    printf("Başlangıç stack A:\n");
    print_stack(a);

    // Indexleme
    index_stack(a);

    printf("\nIndex atandıktan sonra stack A:\n");
    print_stack(a);

    // Radix sort uygula
    radix_sort(&a, &b);

    printf("\nRadix sort sonrası stack A:\n");
    print_stack(a);

    return 0;
}
