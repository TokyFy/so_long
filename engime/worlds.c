/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worlds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:00:43 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/24 13:26:08 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engime.h"
#include <stdlib.h>
#include <unistd.h>

void	debug_grid(t_mlx_image img, int color)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < img.heigth)
	{
		x = 0;
		while (x < img.width)
		{
			if (x % 32 == 0 || y % 32 == 0)
				put_pixel_img(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	init_static_entity(t_state *global, t_entity *entity)
{
	t_animation	**animations;

	animations = malloc(sizeof(t_animation *));
	if (entity->type == 1)
	{
		if (entity->x == 0 && entity->y == 0)
			animations[0] = init_animation(global->frame[12], 60, 1);
		else if (entity->y == 0 && entity->x + 1 == global->worlds->w)
			animations[0] = init_animation(global->frame[13], 60, 1);
		else if (entity->x == 0 && entity->y + 1 == global->worlds->h)
			animations[0] = init_animation(global->frame[14], 60, 1);
		else if (entity->x + 1 == global->worlds->w && entity->y
			+ 1 == global->worlds->h)
			animations[0] = init_animation(global->frame[15], 60, 1);
		else if (entity->y == 0)
			animations[0] = init_animation(global->frame[8], 60, 1);
		else if (entity->y + 1 == global->worlds->h)
			animations[0] = init_animation(global->frame[9], 60, 1);
		else if (entity->x == 0)
			animations[0] = init_animation(global->frame[10], 60, 1);
		else if (entity->x + 1 == global->worlds->w)
			animations[0] = init_animation(global->frame[11], 60, 1);
		else
			animations[0] = init_animation(global->frame[17 + ft_random(0, 7)],
					60, 1);
	}
	else if (entity->type == 2)
		animations[0] = init_animation(global->frame[27 + ft_random(0, 3)],
				ft_random(8, 12), 4);
	else if (entity->type == 3)
		animations[0] = init_animation(global->frame[31], 60, 1);
	else
		animations[0] = init_animation(global->frame[26 - (ft_random(1,
						9) == 5)], 60, 1);
	entity->direction = 0;
	entity->idle = 1;
	entity->c_animation = 1;
	entity->animation = animations;
}

void	free_2d_int(int **arr, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	init_maps(t_state *global, char *ber_file)
{
	t_maps	*worlds;
	int		i;
	int		j;
	int		**table;

	worlds = malloc(sizeof(t_maps));
	table = ber_file_parser(ber_file, &worlds->w, &worlds->h);
	if (!table)
	{
		free(worlds);
		exit_game(global);
		return ;
	}
	worlds->table = malloc(sizeof(t_entity *) * worlds->h);
	global->worlds = worlds;
	global->worlds->collect = 0;
	i = 0;
	while (i < global->worlds->h)
	{
		worlds->table[i] = malloc(sizeof(t_entity *) * worlds->w);
		j = 0;
		while (j < global->worlds->w)
		{
			worlds->table[i][j] = malloc(sizeof(t_entity));
			worlds->table[i][j]->type = table[i][j];
			worlds->table[i][j]->x = j;
			worlds->table[i][j]->y = i;
			if (table[i][j] == 2)
			{
				global->worlds->collect++;
			}
			if (table[i][j] == 4)
			{
				global->main_caracter->x = j * SCALE;
				global->main_caracter->y = i * SCALE;
			}
			init_static_entity(global, worlds->table[i][j]);
			j++;
		}
		i++;
	}
	free_2d_int(table, worlds->h);
}

int	verify_line(char *str, int *w, int *h)
{
	int	error;

	error = 0;
	(void)(h);
	if (*w == -1)
	{
		*w = ft_strlen_set(str, "01PCE");
	}
	if (str && (unsigned int)*w != ft_strlen_set(str, "01PCE"))
	{
		ft_putstr_fd("Error : Map line should be the same size\n", 2);
		error = 1;
	}
	if (str && !valid_map_line(str))
	{
		ft_putstr_fd("Error : the maps should only conten 01PCE\n", 2);
		error = 1;
	}
	return (error);
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
	{
		ft_putstr_fd("Error : Map not found\n", 2);
		return (NULL);
	}
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
