/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:57:25 by rafaria           #+#    #+#             */
/*   Updated: 2024/04/17 15:38:24 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_all(int argc, char **argv, t_stack *stack_a)
{
	char	*joind_args;

	if (argc == 1)
	{
		return (-1);
	}
	if (argc == 2 && ((argv[1][0] == '\0') || check_args2(argv[1]) == 0))
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (argc >= 2)
	{
		joind_args = ft_strjoin(argc, argv, " ");
		if (initialization_with_split(stack_a, joind_args) == -1)
		{
			free(joind_args);
			return (-1);
		}
		free(joind_args);
		index_the_index(&stack_a);
		return (1);
	}
	return (0);
}

int	check_entire_base(t_stack *stack_a, char **string, char *str,
		int count_elements)
{
	if (check_base(count_elements, string) == 1 && (count_elements == 2))
	{
		free_array((size_t)count_elements, string);
		return (-1);
	}
	if (check_base(count_elements, string) == 0)
	{
		free_array((size_t)count_elements, string);
		free(str);
		exit_error(&stack_a, &stack_a);
	}
	return (1);
}

int	initialization_with_split(t_stack *stack_a, char *str)
{
	int		i;
	int		count_elements;
	char	**string;

	i = 2;
	count_elements = count_words(str, ' ');
	string = ft_split(str, ' ');
	if (check_entire_base(stack_a, string, str, count_elements) == -1)
		return (-1);
	stack_a->data = ft_atoi(string[1]);
	stack_a->sign = 0;
	stack_a->index = -1;
	stack_a->size_a = count_elements;
	if (count_elements > 2)
	{
		while (i < count_elements)
		{
			add_to_end_linklist(stack_a, string[i]);
			i++;
		}
		free_array((size_t)count_elements, string);
	}
	return (0);
}

t_stack	*new_stack(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!new)
		return (NULL);
	new->data = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*add_to_end_linklist(t_stack *stack, char *value)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (0);
	node->sign = 0;
	node->data = ft_atoi(value);
	node->index = -1;
	node->prev = NULL;
	node->next = NULL;
	last_node = stack;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	last_node->next = node;
	node->prev = last_node;
	node->next = NULL;
	return (stack);
}
//-----------------------------