/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:27:26 by rafaria           #+#    #+#             */
/*   Updated: 2024/04/04 15:40:02 by raphox           ###   ########.fr       */
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

	else if (i == ft_strlen(str))
		return (1);
	return (0);
}

int	check_base(int count_words, char **str)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	// printf("%d Count words \n:", count_words);
	// printf("%s atoi \n:", "0");

	while (y < count_words)
	{
		i = y + 1;
		while (i < count_words)
		{
			if ((chck(str[y]) == 0) || ft_atoi(str[y]) < -2147483648 || ft_atoi(str[y]) > 2147483647)
				return (0);
			if (ft_atoi(str[y]) == ft_atoi(str[i]))
				return (0);
			i++;
		}
		y++;
	}
	return (1);
}
