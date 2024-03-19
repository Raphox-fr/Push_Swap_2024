/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:07 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/19 17:47:56 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	push_a_b(stack_b, stack_a, 0);
	push_a_b(stack_b, stack_a, 0);
	push_a_b(stack_b, stack_a, 0);
	push_a_b(stack_b, stack_a, 0);
	push_a_b(stack_b, stack_a, 0);
	// swap_a_b(stack_a, 0);
	// swap_a_b(stack_b, 1);
	// swap_swap_a_b(stack_a, stack_b);
	// push_a_b(stack_a, stack_b, 0);
	// push_a_b(stack_a, stack_b, 1);
	// rotate_a_b(stack_a, 0);
	// rotate_a_b(stack_a, 1);
	// rotate_rotate_a_b(stack_a);
	// reverse_rotate_a_b(stack_a, 0);
	// reverse_rotate_a_b(stack_b, 1);
	// reverse_reverse_rotate_a_b(stack_a, stack_b);
}
//----------------------------------------------------------------------------------------------------------------------------

int	main(int argc, char **argv)
{

	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = new_stack(0);
	stack_b = NULL;
	
	if (initialize_all(argc, argv, stack_a) == -1)
		return (0);	
	
	// Sort -------------------------------------------------------	
	
	if (stack_a->size_a == 2 + 1 && stack_a->data > stack_a->next->data)
		swap_a_b(&stack_a, 0);
	
	else if(stack_a->size_a == 3 + 1)
	{
		if (stack_a->next->next->data != 2)
		{
			if (stack_a->data == 2)
				rotate_a_b(&stack_a, 0);
			else
				reverse_rotate_a_b(&stack_a, 0);
		}
		if (stack_a->data > stack_a->next->data)
			swap_a_b(&stack_a, 0);
	}
	
	
	
	// push_swap(&stack_a, &stack_b);











	//------------------------------------------------------------------------------------------------------------------
	t_stack	*cur;
	t_stack	*stock;

	printf("Stack A: ");
	cur = stack_a;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
	printf("Stack B: ");
	stock = stack_b;
	while (stock != NULL)
	{
		printf("%d ", stock->data);
		stock = stock->next;
	}
	printf("\n");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
