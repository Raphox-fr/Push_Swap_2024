/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:42:00 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/25 16:50:08 by rafaria          ###   ########.fr       */
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
		printf("sa\n");
	else if (i == 1)
		printf("sb\n");
}

void	swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, -1);
	swap(stack_b, -1);
	printf("ss\n");
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
		printf("pa\n");
	else if (i == 1)
		printf("pb\n");
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
		printf("ra\n");
	else if (i == 1)
		printf("rb\n");
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	if (get_stack_size(stack_a) > 1)
		rotate(stack_a, -1);
	if (get_stack_size(stack_b) > 1)
		rotate(stack_b, -1);
	printf("rr\n");
}
//-------------------------------------------------------------