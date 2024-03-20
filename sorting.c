/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:56:40 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/20 17:54:58 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int index_bits;
	int j;
	int size;
	t_stack *stock;
	int max_bits;

	index_bits = 0;
	j = 0;
	stock = *stack_a;
	size = get_stack_size(&stock);
	max_bits = get_max_bits(stack_a);
	
	while (index_bits < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			stock = *stack_a;
			if (((stock->data >> index_bits) & 1) == 1)
				rotate(stack_a, 0);
			else
				push(stack_b, stack_a, 1);
		}
		while (get_stack_size(stack_b) != 0)
		{
			push(stack_a, stack_b, 0);
		}
		index_bits++;
	}
}