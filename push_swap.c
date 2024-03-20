/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:07 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/20 17:55:48 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a, 0);
	push(stack_b, stack_a, 0);
	// push(stack_b, stack_a, 0);
	// push(stack_b, stack_a, 0);
	// push(stack_b, stack_a, 0);
	// swap(stack_a, 0);
	// swap(stack_b, 1);
	// swap_swap(stack_a, stack_b);
	// push(stack_a, stack_b, 0);
	// push(stack_a, stack_b, 1);
	// rotate(stack_a, 0);
	// rotate(stack_a, 1);
	// rotate_rotate(stack_a);
	// reverse_rotate(stack_a, 0);
	// reverse_rotate(stack_b, 1);
	// reverse_reverse_rotate(stack_a, stack_b);
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

	int i;
	i = get_stack_size(&stack_a);
	printf("La taille de la stack est : %d\n", i);

	int j;
	j = get_max_bits(&stack_a);
	printf("La plus grande taille binaire stack A est : %d\n", j);


	radix_sort(&stack_a, &stack_b);






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
