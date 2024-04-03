/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:27:26 by rafaria           #+#    #+#             */
/*   Updated: 2024/04/03 17:26:16 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// count elements  = 2

// str = 1 ; 1 ; 0

int	chck(char *str)
{
	int	i;

	i = 0;
	while (str[i] || str[i] == '0' || (str[i] >= '0' && str[i] <= '9') 
			|| (str[i] == '-' || str[i] == '+'))
		i++;
	if (i != ft_strlen(str))
		return (0);

	if (i == ft_strlen(str))
		return (1);
	return (0);
}

int	check_base(int count_words, char **str)
{
	int	i;
	int	y;
	int	found;

	i = 0;
	y = 0;
	found = 0;

	while (y < count_words - 1)
	{
		y++;
		while (i < count_words)
		{
			
			if ((chck(str[y]) == 0) || ft_atoi(str[y]) > 2147483647
				|| ft_atoi(str[y]) < -2147483648)
				return (0);
			if (ft_atoi(str[y]) == ft_atoi(str[i]))
			{
				found++;
			}
			if (found >= 2)
				return (0);
			i++;
		}
		i = y + 1;
		found = 0;
	}
	return (1);
}
