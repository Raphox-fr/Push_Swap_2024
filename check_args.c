/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:27:26 by rafaria           #+#    #+#             */
/*   Updated: 2024/03/12 16:16:40 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// count elements  = 2

// string = 1 ; 1 ; 0

int check_letters_in_args(char *str)
{
	int i;
	i = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
	{
		i++;
	}

	if (i != ft_strlen(str))
		return (0);
	if (i == ft_strlen(str))
		return (1);
}

int	check_base(int count_words, char **string)
{
	int	i;
	int	index;
	int found;

	i = 0;
	index = 0;
	found = 0;

	while (index < count_words - 1)
	{
		index++;
		while (i < count_words)
		{
			if ((check_letters_in_args(string[index]) == 0))
				return (0);
			if (ft_atoi(string[index]) > 2147483647 || ft_atoi(string[index]) < -2147483648)
				return (0);
			if (ft_atoi(string[index]) == ft_atoi(string[i]))
				found++;
			if (found >= 2)
				return (0);
			i++;
		}
		i = 0;
		found = 0;
	}
	return (1);
}


// mediane
// 3point min / max et mediane
// push tout le reste dans b
// boucler toute la stack break;
// 3 etapes
// quel est le prochain plus grand e la pile de B pour toutes les valeurs par rapport a pile a
// stock la psotion de sa poitsion dans a
// tu additionnes les positions
// count_words = 2, on prend le 1 er pqrqmeres