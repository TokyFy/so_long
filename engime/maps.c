/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:52:00 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/24 09:11:02 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engime.h"

int	valid_route(int **table, int width, int heigh)
{
	int	p_x;
	int	p_y;
	int	i;
	int	j;

	init_zero(&p_x, &p_y, &j, &i);
	if (!have_only_one_player_exit(heigh, width, table)
		|| !have_at_least_one_collectible(heigh, width, table))
		return (0);
	while (i < heigh)
	{
		j = 0;
		while (j < width)
		{
			if (table[i][j] == 4)
			{
				p_x = j;
				p_y = i;
			}
			j++;
		}
		i++;
	}
	reachable_by_player(p_x, p_y, table);
	return (is_all_reachable(heigh, width, table));
}

int	validate_table(int ***table, int width, int heigh)
{
	int	error;

	error = 0;
	if (width == heigh)
	{
		error = 1;
		ft_putstr_fd("Error : squared Maps !\n", 2);
	}
	if (!valid_wall(*table, width, heigh))
		error = 1;
	if (!valid_route(*table, width, heigh))
		error = 1;
	if (error)
	{
		free_2d_int(*table, heigh);
		*table = NULL;
	}
	return (error);
}

int	**fill_map_from_ber(t_list *line, int width, int heigh)
{
	int		w;
	int		h;
	t_list	*lst;
	int		**table;

	w = 0;
	h = 0;
	lst = line;
	table = ft_calloc(sizeof(int *), heigh);
	while (h < heigh)
	{
		table[h] = ft_calloc(sizeof(int), width);
		w = 0;
		while (w < width)
		{
			fill_ceil(&table[h][w], ((char *)(line->content))[w]);
			w++;
		}
		line = line->next;
		h++;
	}
	ft_lstclear(&lst, free);
	validate_table(&table, width, heigh);
	return (table);
}
