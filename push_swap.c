/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:07 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/23 19:01:28 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//----------------------------
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

	// if (get_stack_size(&stack_a) <= 5)
	// {
	// 	sort_less_5(&stack_a, &stack_b);
	// }
	// else
	// {
	radix_sort(&stack_a, &stack_b);
	// }


	int i;
	i = get_stack_size(&stack_a);
	printf("La taille de la stack est : %d\n", i);
	int j;
	j = get_max_bits(&stack_a);
	printf("La plus grande taille binaire stack A est : %d\n", j);
	int show_count;
	show_count = is_sorted(&stack_a);
	printf("Si le nombre correspond %d == %d\n", show_count, i);
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