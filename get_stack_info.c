/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:53:46 by raphox            #+#    #+#             */
/*   Updated: 2024/03/23 18:57:08 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack **stack)
{
	int		max;
	int		max_bits;
	t_stack	*stock;

	stock = *stack;
	max = stock->data;
	max_bits = 0;
	while (stock != NULL)
	{
		if (stock->data >= max)
			max = stock->data;
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
	int		max;
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

int	get_min(t_stack **stack)
{
	int		max;
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
