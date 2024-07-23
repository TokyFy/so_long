/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:46:13 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/23 15:16:32 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				return (0);
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

	i = 0;
	j = 0;
	p = 0;
	e = 0;
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
	return (p == 1 && e > 0);
}

int	have_at_least_one_collectible(int row, int col, int **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (array[i][j] == 2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
