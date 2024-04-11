/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:56:40 by rafaria           #+#    #+#             */
/*   Updated: 2024/04/11 18:45:29 by raphox           ###   ########.fr       */
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

void	sort_3_elements(t_stack **stack_a)
{
	if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->next->data < (*stack_a)->next->next->data)
		return ;
	else if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->data)
	{
		reverse_rotate(stack_a, 0);
		swap(stack_a, 0);
	}
	else if ((*stack_a)->data < (*stack_a)->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->data)
		reverse_rotate(stack_a, 0);
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->data
		&& (*stack_a)->next->data < (*stack_a)->next->next->data)
		rotate(stack_a, 0);
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->data)
		swap(stack_a, 0);
	else if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		rotate(stack_a, 0);
		swap(stack_a, 0);
	}
}

int	sort_4_elements(t_stack **stack_a, t_stack **stack_b)
{
	while (get_min_position(stack_a) != 1)
	{
		if (get_min_position(stack_a) > 3)
			reverse_rotate(stack_a, 0);
		else if (get_min_position(stack_a) <= 3)
			rotate(stack_a, 0);
	}
	push(stack_b, stack_a, 1);
	sort_3_elements(stack_a);
	push(stack_a, stack_b, 1);
	return (0);
}

int	sort_5_elements(t_stack **stack_a, t_stack **stack_b)
{
	int	y;

	y = 0;
	while (y != 2)
	{
		while (get_min_position(stack_a) != 1)
		{
			if (get_min_position(stack_a) > 3)
				reverse_rotate(stack_a, 0);
			else if (get_min_position(stack_a) <= 3)
				rotate(stack_a, 0);
		}
		push(stack_b, stack_a, 1);
		y++;
	}
	sort_3_elements(stack_a);
	push(stack_a, stack_b, 1);
	push(stack_a, stack_b, 1);
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
			if (((stock->index >> index_bits) & 1) == 1)
				rotate(stack_a, 0);
			else
				push(stack_b, stack_a, 1);
		}
		while (get_stack_size(stack_b) != 0)
			push(stack_a, stack_b, 0);
		index_bits++;
	}
}
