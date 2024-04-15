/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:07 by rafaria           #+#    #+#             */
/*   Updated: 2024/04/14 21:54:25 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = new_stack(0);
	stack_b = NULL;

	// printf("voici l argc : %d argv : %s", argc, argv[1]);
	if (initialize_all(argc, argv, stack_a) == -1)
	{
		free_both_stack(&stack_a, &stack_b);
		return(0);	
	}
	if (is_sorted(&stack_a) == get_stack_size(&stack_a))
		free_both_stack(&stack_a, &stack_b);
	if (get_stack_size(&stack_a) == 2)
		swap(&stack_a, 0);
	if (get_stack_size(&stack_a) == 3)
		sort_3_elements(&stack_a);
	else if (get_stack_size(&stack_a) == 4)
		sort_4_elements(&stack_a, &stack_b);
	else if (get_stack_size(&stack_a) == 5)
		sort_5_elements(&stack_a, &stack_b);
	else if (get_stack_size(&stack_a) > 5)
		radix_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

// printf("-------------\n");
// t_stack	*cur;
// t_stack	*stock;
// printf("Stack A : ");
// cur = stack_a;
// while (cur != NULL)
// {
// 	printf("%ld ", cur->data);
// 	cur = cur->next;
// }

// printf("\nStack B: ");
// stock = stack_b;
// while (stock != NULL)
// {
// 	printf("%ld ", stock->data);
// 	stock = stock->next;
// }
// printf("\n");
