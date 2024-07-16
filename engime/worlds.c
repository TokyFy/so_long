/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worlds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:00:43 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/16 14:44:38 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engime.h"

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
		{
			animations[0] = init_animation(global->frame[12], 60, 1);
		}
		else if (entity->y == 0 && entity->x + 1 == global->worlds->w)
		{
			animations[0] = init_animation(global->frame[13], 60, 1);
		}
		else if (entity->x == 0 && entity->y + 1 == global->worlds->h)
		{
			animations[0] = init_animation(global->frame[14], 60, 1);
		}
		else if (entity->x + 1 == global->worlds->w && entity->y
			+ 1 == global->worlds->h)
		{
			animations[0] = init_animation(global->frame[15], 60, 1);
		}
		else if (entity->y == 0)
		{
			animations[0] = init_animation(global->frame[8], 60, 1);
		}
		else if (entity->y + 1 == global->worlds->h)
		{
			animations[0] = init_animation(global->frame[9], 60, 1);
		}
		else if (entity->x == 0)
		{
			animations[0] = init_animation(global->frame[10], 60, 1);
		}
		else if (entity->x + 1 == global->worlds->w)
		{
			animations[0] = init_animation(global->frame[11], 60, 1);
		}
		else
		{
			animations[0] = init_animation(global->frame[17
					+ generateRandomNumber(0, 7)], 60, 1);
		}
	}
	else if (entity->type == 2)
	{
		animations[0] = init_animation(global->frame[27
				+ generateRandomNumber(0, 3)], generateRandomNumber(8, 12), 4);
	}
	else if(entity->type == 3)
	{
		animations[0] = init_animation(global->frame[31], 60 , 1);
	}
	else{
		animations[0] = init_animation(global->frame[26
				- (generateRandomNumber(1, 9) == 5)], 60, 1);
	}
	entity->direction = 0;
	entity->idle = 1;
	entity->c_animation = 0;
	entity->animation = animations;
}

void	init_maps(t_state *global)
{
	t_maps	*worlds;
	int		i;
	int		j;

	worlds = malloc(sizeof(t_maps));
	int **_i = ber_file_parser("./engime/map.ber" , &worlds->w , &worlds->h);
	worlds->table = malloc(sizeof(t_entity *) * worlds->h);
	global->worlds = worlds;
	global->worlds->collect = 0;
	i = 0;
	j = 0;
	while (i < global->worlds->h)
	{
		worlds->table[i] = malloc(sizeof(t_entity *) * worlds->w);
		j = 0;
		while (j < global->worlds->w)
		{
			worlds->table[i][j] = malloc(sizeof(t_entity));
			worlds->table[i][j]->type = _i[i][j];
			worlds->table[i][j]->x = j;
			worlds->table[i][j]->y = i;
			if(_i[i][j] == 3)
			{
				global->worlds->collect++;
			}
			if(_i[i][j] == 4)
			{
				global->main_caracter->x = j * SCALE;
				global->main_caracter->y = i * SCALE;
			}
			init_static_entity(global, worlds->table[i][j]);
			j++;
		}
		i++;
	}
}