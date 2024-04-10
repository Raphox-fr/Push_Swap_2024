/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:53:46 by raphox            #+#    #+#             */
/*   Updated: 2024/04/10 21:19:36 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	get_max_bits(t_stack **stack)
{
	long int		max;
	long int		max_bits;
	t_stack	*stock;

	stock = *stack;
	max = stock->index;
	max_bits = 0;
	while (stock != NULL)
	{
		if (stock->index >= max)
			max = stock->index;
		stock = stock->next;
	}
	while (max >> max_bits)
	{
		max_bits++;
	}
	return (max_bits);
}

int	get_max(t_stack **stack)
{
	long int		max;
	t_stack	*stock;

	stock = *stack;
	max = stock->data;
	while (stock != NULL)
	{
		if (stock->data >= max)
			max = stock->data;
		stock = stock->next;
	}
	return (max);
}

int	get_max_position(t_stack **stack)
{
	int localize;
	int long max;
	t_stack	*stack_to_find;

	max = get_max(stack);
	localize = 1;
	stack_to_find = *stack;
	
	while (stack_to_find != NULL)
	{
		if (stack_to_find->data == max)
			return (localize);
		localize++;
		stack_to_find = stack_to_find->next;
	}
		// printf("la position du max est ici : %d", localize);
	return (0);
}




int	get_min_position(t_stack **stack)
{
	int localize;
	int long min;
	t_stack	*stack_to_find;

	min = get_min(stack);
	localize = 1;
	stack_to_find = *stack;
	
	while (stack_to_find != NULL)
	{
		if (stack_to_find->data == min)
		{
			return (localize);
		}
		localize++;
		stack_to_find = stack_to_find->next;
	}
		// printf("la position du max est ici : %d", localize);
	return (0);
}



int	get_min(t_stack **stack)
{
	long int		max;
	t_stack	*stock;

	stock = *stack;
	max = get_max(stack);
	while (stock != NULL)
	{
		if (stock->data <= max)
			max = stock->data;
		stock = stock->next;
	}
	return (max);
}

int	get_stack_size(t_stack **stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
