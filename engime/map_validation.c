/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:39:58 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/24 13:13:09 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "engime.h"

int	valid_map_line(char *str)
{
	while (*str)
	{
		if (!(*str == '0' || *str == '1' || *str == 'C' || *str == 'P'
				|| *str == 'E' || *str == '\n'))
			return (0);
		str++;
	}
	return (1);
}

int	valid_wall(int **table, int width, int heigh)
{
	int	i;
	int	j;
	int	error;

	error = 0;
	i = 0;
	j = 0;
	while (i < heigh)
	{
		j = 0;
		while (j < width)
		{
			if ((i == 0 || i == heigh - 1) && table[i][j] != 1)
				error = 1;
			else if ((j == 0 || j == width - 1) && table[i][j] != 1)
				error = 1;
			if (error)
				return (ft_putstr_fd("Error , Not sunrounded by 1!\n", 2), 0);
			j++;
		}
		i++;
	}
	return (1);
}
