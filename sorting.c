/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:56:40 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/25 16:44:00 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack_a)
{
	int		count;
	t_stack	*tmp;

	count = 1;
	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->data < tmp->next->data)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	sort_less_5(t_stack **stack_a, t_stack **stack_b)
{
	while (get_stack_size(stack_a) > 0)
	{
		do_sort_less_5(stack_a, stack_b);
	}
	*stack_a = NULL;
	while (get_stack_size(stack_b) > 0)
	{
		push(stack_a, stack_b, 1);
	}
	*stack_b = NULL;
	return (0);
}

int	do_sort_less_5(t_stack **stack_a, t_stack **stack_b)
{
	int		pin;
	int		localize_that_bitch;
	t_stack	*stock;

	stock = *stack_a;
	pin = get_min(stack_a);
	localize_that_bitch = 0;
	while (stock != NULL)
	{
		if (stock->data == pin)
		{
			while (localize_that_bitch > 0)
			{
				rotate(stack_a, 0);
				localize_that_bitch--;
			}
			push(stack_b, stack_a, 1);
		}
		localize_that_bitch++;
		stock = stock->next;
	}
	return (0);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		index_bits;
	int		j;
	int		size;
	t_stack	*stock;
	int		max_bits;

	index_bits = 0;
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
			push(stack_a, stack_b, 0);
		index_bits++;
	}
}
