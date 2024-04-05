/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:27:26 by rafaria           #+#    #+#             */
/*   Updated: 2024/04/05 19:53:52 by rafaria          ###   ########.fr       */
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
	if (ft_atoi(str[1]) < -2147483648 || ft_atoi(str[1]) > 2147483647)
		return (0);

	// printf("%d", count_words);
	// printf("%s\n", str[0]);
	// printf("%s\n", str[1]);
	// printf("%s\n", str[2]);
	// printf("%s\n", str[3]);
	// printf("%s\n", str[4]);

	while (y < count_words)
	{
		i = y + 1;
		while (i < count_words)
		{
			if ((is_valid_number(str[y]) == 0))
				return (0);
			if (ft_atoi(str[y]) == ft_atoi(str[i]))
				return (0);
			if (ft_atoi(str[y]) < -2147483648 || ft_atoi(str[y]) > 2147483647)
				return (0);
			i++;
		}
		y++;
	}
	if (ft_atoi(str[count_words - 1]) < -2147483648 || ft_atoi(str[count_words - 1]) > 2147483647)
		return (0);
	if ((is_valid_number(str[count_words - 1]) == 0))
		return (0);
	return (1);
}        
	

int		is_valid_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '+' || str[i] != '-')) 
			return (0);
		i++;
	}
	return(1);
}

