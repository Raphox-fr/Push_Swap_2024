/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_negatif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:23:54 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/27 13:34:14 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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



// {
// 	int		index_bits;
// 	int		j;
// 	int		size;
// 	t_stack	*stock;
// 	int		max_bits;

// 	index_bits = 0;
// 	stock = *stack_a;
// 	size = get_stack_size(&stock);
// 	max_bits = get_max_bits(stack_a);
// 	while (index_bits < max_bits)
// 	{
// 		j = 0;
// 		while (j++ < size)
// 		{
// 			stock = *stack_a;
// 			if (((stock->data >> index_bits) & 1) == 1)
// 				rotate(stack_a, 0);
// 			else
// 				push(stack_b, stack_a, 1);
// 		}
// 		while (get_stack_size(stack_b) != 0)
// 			push(stack_a, stack_b, 0);
// 		index_bits++;
// 	}
// }


// void	push_negative_to_stack_b(t_stack **stack_a, t_stack **stack_b)
// {
	
// }

// void	turn_stack_b_to_negative(t_stack **stack_a,t_stack **stack_b)
// {
	
// }