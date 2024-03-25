/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:07:45 by raphox            #+#    #+#             */
/*   Updated: 2024/03/25 16:53:55 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	reverse_rotate(t_stack **stack_a_b, int i)
{
	int		j;

	j = get_stack_size(stack_a_b);
	if (j == 0 || j == 1)
		return ;
	while (j != 1)
	{
		rotate(stack_a_b, -1);
		j--;
	}
	if (i == 0)
		printf("rra\n");
	else if (i == 1)
		printf("rrb\n");
}

void	reverse_reverse_rotate(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, -1);
	reverse_rotate(stack_b, -1);
	printf("rrr\n");
}
