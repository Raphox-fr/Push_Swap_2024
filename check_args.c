/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:27:26 by rafaria           #+#    #+#             */
/*   Updated: 2024/04/15 19:42:13 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// count elements  = 2

// str = 1 ; 1 ; 0

int	check_base(int count_words, char **str)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (y < count_words)
	{
		i = y + 1;
		while (i < count_words)
		{
			if (ft_atoi(str[y]) == ft_atoi(str[i]))
				return (0);
			i++;
		}
		y++;
	}
	y = 1;
	while (y < count_words)
	{
		if (is_valid_number(str[y]) == 0)
			return (0);
		y++;
	}
	return (1);
}

int	is_valid_number(char *str)
{
	int	i;
	int	found;

	found = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '+' && str[i] != '-'))
		{
			return (0);
		}
		if (str[i] == '+' || str[i] == '-')
		{
			found++;
			if ((i > 1) && (str[i] == '+' || str[i] == '-')
				&& (str[i - 1] != ' '))
				return (0);
			if (found == 2)
				return (0);
		}
		if (is_exception_number(str) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_exception_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((i >= 1) && (str[i] == '+' || str[i] == '-') && (str[i - 1] != ' '))
			return (0);
		i++;
	}
	if ((ft_strlen(str) == 1) && (str[0] == '-' || str[0] == '+'))
		return (0);
	if (ft_atoi(str) < -2147483648 || ft_atoi(str) > 2147483647)
		return (0);
	return (1);
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
