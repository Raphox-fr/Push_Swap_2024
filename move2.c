/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:07:45 by raphox            #+#    #+#             */
/*   Updated: 2024/03/23 17:08:05 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
