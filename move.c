/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:42:00 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/20 14:50:08 by rafaria          ###   ########.fr       */
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
		tmp = *stack_b;// tmp prend la valeur 1 er element de B
		*stack_b = (*stack_b)->next;// stack b = stack b est egal a son suivant donc le premier element est retirer
		tmp->next = *stack_a;// La suite de tmp prend le reste de la stack_a
		*stack_a = tmp;// tmp = (premier element de b) + la suite de a
	}
	else
		return ;
	if (i == 0)
		printf("pa\n");
	else if (i == 1)
		printf("pb\n");
}
//-------------------------------------------------------------

void	rotate(t_stack **stack_a_b, int i)
{
	t_stack	*end_filler;
	t_stack	*slide;

	end_filler = malloc(sizeof(t_stack));
	if (end_filler == NULL)
		return ;
	end_filler->data = (*stack_a_b)->data;
	end_filler->next = NULL;
	*stack_a_b = (*stack_a_b)->next;
	slide = *stack_a_b;
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

void	reverse_rotate(t_stack **stack_a_b, int i)
{
	int		j;
	t_stack	*slide;

	j = 0;
	slide = *stack_a_b;
	while (slide->next != NULL)
	{
		slide = slide->next;
		j++;
	}
	while (j != 0)
	{
		rotate(stack_a_b, -1);
		j--;
	}
	if (i == 0)
		printf("rra\n");
	else if (i == 1)
		printf("rrb\n");
}

void	reverse_reverse_rotate_a_b(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, -1);
	reverse_rotate(stack_b, -1);
	printf("rrr\n");
}
