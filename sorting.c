/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:56:40 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/21 21:06:45 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack **stack_a)
{
	int count;
	count = 1;
	t_stack *tmp;
	tmp = *stack_a;
	
	while (tmp->next != NULL)
	{
		if (tmp->data < tmp->next->data)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int sort_less_5_args(t_stack **stack_a, t_stack **stack_b)
{
	int pin;
	t_stack *stock;

	pin = 0;
	stock = *stack_a;
	int i;
	i = get_stack_size(stack_a);

	while (i != 1)
	{
		pin = get_max(stack_a);
		printf("%d", pin);
		
		while (stock->next != NULL)
		{
			if (stock->data == pin)
			{
				*stack_a = stock;
				push(stack_b, stack_a, 1);
				break;
			}
			stock = stock->next;
		}
		i--;
	}
	*stack_a = new_stack(0);


	return (0);
	
	
}



































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