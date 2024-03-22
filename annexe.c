/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:21:37 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/22 15:44:35 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int get_max_bits(t_stack **stack)
{
	int max;
	int max_bits;
	t_stack *stock;

	stock = *stack;
	max = stock->data;
	max_bits = 0;

	while (stock != NULL)
	{
		if (stock->data >= max)
			max = stock->data;
		stock = stock->next;
	}
	while (max >> max_bits)
	{
		max_bits++;
	}
	return (max_bits);
}

int get_max(t_stack **stack)
{
	int max;
	t_stack *stock;

	stock = *stack;
	max = stock->data;

	while (stock != NULL)
	{
		if (stock->data >= max)
			max = stock->data;
		stock = stock->next;
	}
	return (max);
}

int get_min(t_stack **stack)
{
	int max;
	t_stack *stock;

	stock = *stack;
	max = get_max(stack);

	while (stock != NULL)
	{
		if (stock->data <= max)
			max = stock->data;
		stock = stock->next;
	}
	return (max);
}





int	get_stack_size(t_stack **stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

//----------------------------------------------------------

long int	ft_atoi(char *str)
{
	long int	neg;
	long int	num;
	long int	i;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_count_string(int size, char **strs, char *sep)
{
	int	i;
	int	taille;
	int	countsep;

	i = 0;
	taille = 0;
	countsep = ft_strlen(sep);
	while (i < size)
	{
		taille = taille + ft_strlen(strs[i]);
		i++;
	}
	taille = taille + (countsep * (size - 1));
	return (taille);
}

char	*real_bruv(int size, char *tab, char **strs, char *sep)
{
	int	i;
	int	j;
	int	countall;

	i = 0;
	j = 0;
	countall = 0;
	while (j < size)
	{
		while (strs[j][i])
			tab[countall++] = strs[j][i++];
		j++;
		if (j == size)
		{
			tab[countall] = '\0';
			return (tab);
		}
		i = 0;
		while (sep[i])
			tab[countall++] = sep[i++];
		i = 0;
	}
	tab[countall] = '\0';
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *tab;
	int countall;
	char *anh;

	if (size == 0)
	{
		anh = malloc(1);
		*anh = '\0';
		return (anh);
	}
	countall = ft_count_string(size, strs, sep);
	tab = malloc((sizeof(char)) * (countall + 1));
	if (tab == NULL)
		return (tab);
	if ((real_bruv(size, tab, strs, sep)) == tab)
		return (tab);
	return (tab);
}