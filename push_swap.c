/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:07 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/15 18:02:41 by raphox           ###   ########.fr       */
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

int main(int argc, char **argv)
{
	char *joind_args;
	t_stack *stack_a;
	t_stack *stack_b;
	stack_a = new_stack(0);
	stack_b = NULL;

	if (argc == 1)
	{
		free_stack(&stack_a);
		return (0);
	}

	if (argc == 2)
	{
		joind_args = ft_strjoin(argc, argv, " ");
		initializatiom_with_split(stack_a, joind_args);
		free(joind_args);
	}

	if (argc >= 3)
	{
		joind_args = ft_strjoin(argc, argv, " ");
		initializatiom_with_split(stack_a, joind_args);
		free(joind_args);
	}

	// push_swap(&stack_a, &stack_b);

//------------------------------------------------------------------------------------------------------------------

	printf("Stack A: ");
	t_stack *cur = stack_a;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");

	printf("Stack B: ");
	t_stack *stock = stack_b;
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



