/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:57:25 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/14 17:09:29 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int initializatiom_with_split(t_stack *stack_a, int argc, char *str)
{
	int i;
	int count_elements;
	char **string;
	
	i = 2;
	count_elements = count_words(str, ' ');
	string = ft_split(str, ' ');

	
	if (check_base(count_elements, string) == 0)
	{
		exit_error(&stack_a, &stack_a);
		exit(1);
	}
	stack_a->data = ft_atoi(string[1]);
	if (count_elements > 2)
	{
		while (i < count_elements)
		{
			add_to_end_linklist(stack_a, string[i]);
			i++;
		}
	free_array((size_t)count_elements, string);
	return (0);
	}
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
	// free(new);
	return (new);
}


t_stack *add_to_end_linklist(t_stack *stack, char *value)
{
	t_stack *node;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (0);
	t_stack *last_node; 

	
	node->data = ft_atoi(value);
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


//----------------------------------------------------------------------------------

static size_t	count_words(char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			count++;
			while (*(s + i) && *(s + i) != c)
				i++;
		}
		else if (*(s + i) == c)
			i++;
	}
	return (count);
}

static size_t	get_word_len(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}



static char	**split(char *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(array + i) = ft_substr(s, j, get_word_len(&*(s + j), c));
		if (!*(array + i))
		{
			free_array(i, array);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**ft_split(char *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, words);
	return (array);
}







