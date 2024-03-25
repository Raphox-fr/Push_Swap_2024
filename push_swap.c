/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:07 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/25 22:45:11 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = new_stack(0);
	stack_b = NULL;
	if (initialize_all(argc, argv, stack_a) == -1)
		return (0);
	if (is_sorted(&stack_a) == get_stack_size(&stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	if (get_stack_size(&stack_a) <= 5)
	{
		sort_less_5(&stack_a, &stack_b);
	}
	else
	{
		radix_sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
