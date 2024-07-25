/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worlds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:00:43 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/24 14:32:14 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engime.h"
#include <stdlib.h>
#include <unistd.h>

void	fill_worlds(t_state *global, int **table, t_maps *worlds)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	worlds->table = malloc(sizeof(t_entity *) * worlds->h);
	while (i < global->worlds->h)
	{
		worlds->table[i] = malloc(sizeof(t_entity *) * worlds->w);
		j = 0;
		while (j < global->worlds->w)
		{
			worlds->table[i][j] = new_entity(table[i][j], j, i);
			if (table[i][j] == 2)
				global->worlds->collect++;
			if (table[i][j] == 4)
			{
				global->main_caracter->x = j * SCALE;
				global->main_caracter->y = i * SCALE;
			}
			init_static_entity(global, worlds->table[i][j++]);
		}
		i++;
	}
}

void	init_maps(t_state *global, char *ber_file)
{
	t_maps	*worlds;
	int		**table;

	worlds = malloc(sizeof(t_maps));
	worlds->table = NULL;
	global->worlds = worlds;
	global->worlds->collect = 0;
	table = ber_file_parser(ber_file, &worlds->w, &worlds->h);
	if (!table)
	{
		free(worlds);
		global->worlds = NULL;
		exit_game(global);
		return ;
	}
	fill_worlds(global, table, worlds);
	free_2d_int(table, worlds->h);
}

int	**ber_file_parser(char *path, int *w, int *h)
{
	int		fd;
	t_list	*line;
	char	*str;
	int		error;

	error = 0;
	fd = open(path, O_RDONLY);
	line = NULL;
	str = NULL;
	if (fd == -1)
		return (ft_putstr_fd("Error : Map not found\n", 2), NULL);
	*w = -1;
	*h = 0;
	while (line == NULL || str != NULL)
	{
		str = get_next_line(fd);
		ft_lstadd_back(&line, ft_lstnew(str));
		error += verify_line(str, w, h);
		(*h)++;
	}
	if (error)
		return (ft_lstclear(&line, free), NULL);
	close(fd);
	return (fill_map_from_ber(line, (*w), --(*h)));
}
