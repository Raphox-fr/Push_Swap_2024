/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:56:25 by raphox            #+#    #+#             */
/*   Updated: 2024/04/03 17:09:24 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>
#include <stdio.h>

size_t	count_words(char *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (s[0] == c || s[ft_strlen((char *)s)] == c)
	{
		while (s[i] == c)
			i ++;
	}
	while (s[i])
	{
		if (s[i] == c)
		{
			words ++;
			i ++;
			while (s[i] == c)
				i ++;
		}
		else
			i ++;
	}
	if (s[ft_strlen((char *)s) - 1] != c)
		words ++;
	return (words);
}

static int	count_letters(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i ++;
	return (i);
}

static char	*create_tab2(const char *s, char c)
{
	int		j;
	char	*tab2;
	int		mem;
	int		i;

	mem = (count_letters((char *)s, c));
	tab2 = NULL;
	i = 0;
	j = 0;
	tab2 = malloc((mem + 1) * sizeof(char));
	if (!tab2)
		free (tab2);
	while (i < mem && s[i])
		tab2[j++] = s[i++];
	tab2[j] = '\0';
	return (tab2);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		len_s;
	int		words;
	char	**tab;

	i = 0;
	if (s[i])
		words = count_words(s, c);
	else
		words = 0;
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	len_s = 0;
	while (i < words)
	{
		while (s[len_s] == c)
			len_s ++;
		tab[i] = create_tab2(&s[len_s], c);
		if (!tab[i])
			free (tab[i]);
		len_s += ft_strlen(tab[i++]);
	}
	tab[i] = "NULL";
	return (tab);
}
