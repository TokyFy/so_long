/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:46:13 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/24 13:14:37 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engime.h"

void	fill_ceil(int *ceil, char content)
{
	if (content == '1')
		*ceil = 1;
	else if (content == 'C')
		*ceil = 2;
	else if (content == 'E')
		*ceil = 3;
	else if (content == 'P')
		*ceil = 4;
}

void	reachable_by_player(int x, int y, int **arr)
{
	if (arr[y][x] == 1 || arr[y][x] < 0)
		return ;
	arr[y][x] -= 9;
	reachable_by_player(x, y - 1, arr);
	reachable_by_player(x, y + 1, arr);
	reachable_by_player(x - 1, y, arr);
	reachable_by_player(x + 1, y, arr);
}

int	is_all_reachable(int rows, int cols, int **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (array[i][j] > 1)
			{
				ft_putstr_fd("Error\n : Not all elements are reachable", 2);
				return (0);
			}
			if (array[i][j] < 0)
			{
				array[i][j] += 9;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	have_only_one_player_exit(int row, int cols, int **array)
{
	int	i;
	int	j;
	int	p;
	int	e;

	init_zero(&i, &j, &p, &e);
	while (i < row)
	{
		j = 0;
		while (j < cols)
		{
			if (array[i][j] == 3)
				e++;
			if (array[i][j] == 4)
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		ft_putstr_fd("Error : there should be one and only one Player\n", 2);
	if (e != 1)
		ft_putstr_fd("Error : there should be one and only one Exit\n", 2);
	return (p == 1 && e == 1);
}

int	have_at_least_one_collectible(int row, int col, int **array)
{
	int	i;
	int	j;
	int	count_c;

	count_c = 0;
	i = 0;
	j = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (array[i][j] == 2)
				count_c++;
			j++;
		}
		i++;
	}
	if (count_c <= 0)
		ft_putstr_fd("Error : There should be at least one Collectible \n", 2);
	return (count_c > 0);
}
