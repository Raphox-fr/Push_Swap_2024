/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:07 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/13 17:57:23 by rafaria          ###   ########.fr       */
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
	// rotate_rotate_a_b(stack_a, stack_b);
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
		return (0);

	if (argc == 2)
	{
		joind_args = ft_strjoin(argc, argv, " ");
		initializatiom_with_split(stack_a, argc, joind_args);
	}

	if (argc >= 3)
	{
		joind_args = ft_strjoin(argc, argv, " ");
		initializatiom_with_split(stack_a, argc, joind_args);
		
	}
	
	// push_swap(&stack_a, &stack_b);
	
	for (t_stack *stack = stack_a; stack != NULL; stack = stack->next)
		printf("%d\n", stack->data);

	
		printf("Stack A: ");
	for (t_stack *cur = stack_a; cur != NULL; cur = cur->next)
		printf("%d ", cur->data);
	printf("\n");

			printf("Stack B: ");
	for (t_stack *cur = stack_b; cur != NULL; cur = cur->next)
		printf("%d ", cur->data);
		printf("\n");
	return (0);

}



