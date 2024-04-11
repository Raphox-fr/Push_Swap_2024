/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:23:54 by rafaria           #+#    #+#             */
/*   Updated: 2024/04/11 18:41:17 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_for_index(t_stack **stack)
{
	long int	max;
	t_stack		*stock;

	stock = *stack;
	max = get_max(stack);
	while (stock != NULL)
	{
		if (stock->data <= max && stock->index == -1)
			max = stock->data;
		stock = stock->next;
	}
	return (max);
}

int	get_min_position_for_index(t_stack **stack, int index)
{
	int			localize;
	int long	min;
	t_stack		*stack_to_find;

	min = get_min_for_index(stack);
	localize = 1;
	stack_to_find = *stack;
	while (stack_to_find != NULL)
	{
		if (stack_to_find->data == min)
		{
			stack_to_find->index = index;
			return (localize);
		}
		localize++;
		stack_to_find = stack_to_find->next;
	}
	return (0);
}

int	index_the_index(t_stack **stack_a)
{
	int	i;
	int	index;

	index = 0;
	i = get_stack_size(stack_a);
	printf(" zeub : %d \n", i);
	while (i > 0)
	{
		get_min_position_for_index(stack_a, index);
		index++;
		i--;
	}
	return (0);
}
