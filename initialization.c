/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:57:25 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/09 18:24:25 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int initializatiom_with_split(t_stack *stack_a, int argc, char **argv)
{
	int i;
	int count_elements;
	char **string;
	
	i = 1;
	count_elements = get_words_count(argv[1], " ");
	string = ft_split(argv[1], " ");

	
	if (check_base(count_elements, string) == 0)
	{
		printf("Errorup\n");
		exit(1);
	}
	
	if (count_elements == 1)
	{
		stack_a->data = ft_atoi(string[0]);
		stack_a->next = NULL;
		stack_a->prev = NULL;
	}
	
	if (count_elements >= 2)
	{
		stack_a->data = ft_atoi(string[0]);
		while (i < count_elements)
		{
			add_to_end_linklist(stack_a, string[i]);
			i++;
		}
	return (0);
	}
}


int	initializatiom_basic(t_stack *stack_a, int argc, char **argv)
{
	stack_a->data = ft_atoi(argv[1]);

	int i;
	i = 2;

	if (check_base(argc, argv) == 0)
	{
		printf("Error\n");
		exit(1);
	}	
	while (i < argc)
	{
		add_to_end_linklist(stack_a, argv[i]);
		i++;
	}
}





















t_stack	*new_stack(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(new));
	if (!new)
		return (NULL);
	
	new->data = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack *add_to_end_linklist(t_stack *stack, char *data)
{
	
	t_stack *node;
	node = malloc(sizeof(t_stack));
	t_stack *last_node; 

	
	node->data = ft_atoi(data);
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

#include <stdlib.h>

int		is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		++i;
	}
	return (0);
}
// ---------------------------------------------------------------------------------------------------

int		is_word(char c, char cbefore, char *charset)
{
	return (!is_separator(c, charset) && is_separator(cbefore, charset));
}

int		get_words_count(char *str, char *charset)
{
	int	words_count;
	int	i;

	i = 0;
	words_count = 0;
	while (str[i] != '\0')
	{
		if (is_word(str[i], str[i - 1], charset) ||
			(!is_separator(str[i], charset) && i == 0))
			words_count++;
		i++;
	}
	return (words_count);
}

int		*get_words_size(char *str, char *charset)
{
	int	index;
	int	i;
	int	words_count;
	int	*words_size;

	i = 0;
	words_count = get_words_count(str, charset);
	words_size = malloc(words_count * sizeof(int));
	while (i <= words_count)
	{
		words_size[i] = 0;
		i++;
	}
	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if (!is_separator(str[i], charset))
			words_size[index]++;
		else if (i > 0 && !is_separator(str[i - 1], charset))
			index++;
		i++;
	}
	return (words_size);
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		i;
	int		j;
	int		index;
	int		*words_size;

	words = malloc((get_words_count(str, charset) + 1) * sizeof(char*));
	words_size = get_words_size(str, charset);
	index = 0;
	j = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (!is_separator(str[i], charset))
		{
			if (i == 0 || is_word(str[i], str[i - 1], charset))
				words[index] = malloc(words_size[index] * sizeof(char));
			words[index][j] = str[i];
			words[index][++j] = '\0';
		}
		else if (i > 0 && !is_separator(str[i - 1], charset) && ++index)
			j = 0;
	}
	words[get_words_count(str, charset)] = 0;
	return (words);
}





































































// void linked_list_append(t_stack *list, const char *data)
// {

//     t_stack *node = (struct node *)malloc(sizeof(node) * 1);

//     size_t bytes = strlen(data) + 1;
//     node->data = (char *)malloc(sizeof(char) * bytes);


//     ft_strncpy(node->data, data, bytes);
//     node->next = NULL;
    
// 	if (list->prev == NULL)
//         list->prev = node;
	
// 	else
//     {
//         t_stack *tail = list->prev;
//         while (tail->next)
//             tail = tail->next;
//         tail->next = node;
//     }
//     list->size++;
// }

// void linked_list_append(t_stack *stack_a, int args)
// {
//     t_stack *node = (t_stack *)malloc(sizeof(node) * 1);

//     node->data = args;
//     node->next = NULL;
    
// 	if (stack_a->next == NULL)
//         stack_a->next = node;
	
// 	else
//     {
//         t_stack *tail = stack_a->prev;
//         while (tail->next)
//             tail = tail->next;
//         tail->next = node;
//     }
//     stack_a->size++;
// }

// void link_the_linked_list(t_stack stack_a, char *args)
// {
// 	t_stack *stack_b;
// 	stack_b = malloc(sizeof(t_stack) * 1); 

// 	int size;
// 	size = ft_strlen(args);
	
// 	stack_b->data = malloc(sizeof(char) * size);
	
// 	ft_strncpy(stack_b->data, args, size + 1);
	
		
// }




