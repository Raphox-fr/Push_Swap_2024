/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_negatif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:23:54 by rafaria           #+#    #+#             */
/*   Updated: 2024/04/10 21:14:10 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	get_min_for_index(t_stack **stack)
{
	long int		max;
	t_stack	*stock;

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
	int localize;
	int long min;
	t_stack	*stack_to_find;

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
		// printf("la position du max est ici : %d", localize);
	return (0);
}


int index_the_index(t_stack **stack_a)
{
	int i;
	int index;
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
























int	count_negative(t_stack **stack_a)
{
	int count_negative;
	count_negative = 0;
	t_stack *stock;
	stock = *stack_a;
	
	while (stock != NULL)
	{
		if (stock->sign == 1)
			count_negative++;
		stock = stock->next;
	}
	return (count_negative);
}


void	push_negative(t_stack **stack_a, t_stack **stack_b)
{
	int stack_size;
	stack_size = get_stack_size(stack_a);
	t_stack *stock;
	stock = *stack_a;
	
	while (stack_size != 0)
	{
		stock = *stack_a;
		if (stock->sign == 1)
		{
			push(stack_b, stack_a, 1);
		}
		else
			rotate(stack_a, 0);
		stock = stock->next;
		stack_size--;
	}
	
}
void	negative_to_positive(t_stack **stack_a, t_stack **stack_b)
{
	int stack_size;

	stack_size = get_stack_size(stack_b);
	while (stack_size != 0)
	{
		reverse_rotate(stack_b, 1);
		(*stack_b)->data = (*stack_b)->negative_data;
		push(stack_a, stack_b, 0);
		stack_size--;
	}
}
