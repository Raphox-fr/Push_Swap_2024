/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:42:00 by rafaria           #+#    #+#             */
/*   Updated: 2024/04/14 18:33:20 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack_a, int i)
{
	int	a;

	a = (*stack_a)->next->data;
	(*stack_a)->next->data = (*stack_a)->data;
	(*stack_a)->data = a;
	if (i == 0)
		write(1, "sa\n", 3);
	else if (i == 1)
		write(1, "sb\n", 3);
}

void	swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, -1);
	swap(stack_b, -1);
	write(1, "ss\n", 3);
}
//-------------------------------------------------------------

void	push(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*tmp;

	if (*stack_b != NULL)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	else
		return ;
	if (i == 0)
		write(1, "pa\n", 3);
	else if (i == 1)
		write(1, "pb\n", 3);
}
//-------------------------------------------------------------

void	rotate(t_stack **stack, int i)
{
	t_stack	*stock;
	t_stack	*end;

	if (get_stack_size(stack) <= 1)
		return ;
	stock = *stack;
	*stack = (*stack)->next;
	end = get_stack_bottom(*stack);
	stock->next = NULL;
	end->next = stock;
	if (i == 0)
		write(1, "ra\n", 3);
	else if (i == 1)
		write(1, "rb\n", 3);
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	if (get_stack_size(stack_a) > 1)
		rotate(stack_a, -1);
	if (get_stack_size(stack_b) > 1)
		rotate(stack_b, -1);
	write(1, "rr\n", 3);
}
//-------------------------------------------------------------