/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:42:00 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/23 17:08:31 by raphox           ###   ########.fr       */
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
	t_stack	*end_filler;
	t_stack	*slide;

	end_filler = malloc(sizeof(t_stack));
	if (end_filler == NULL)
		return ;
	end_filler->data = (*stack)->data;
	end_filler->next = NULL;
	*stack = (*stack)->next;
	slide = *stack;
	while (slide->next != NULL)
	{
		slide = slide->next;
	}
	slide->next = end_filler;
	if (i == 0)
		printf("ra\n");
	else if (i == 1)
		printf("rb\n");
}

void	rotate_rotate(t_stack **stack_a)
{
	rotate(stack_a, -1);
	rotate(stack_a, -1);
	printf("rr\n");
}
//-------------------------------------------------------------