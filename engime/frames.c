/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:59:14 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/24 15:51:07 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engime.h"

void	render_player(t_state *global)
{
	if (global->main_caracter->idle)
	{
		put_animation_to_image(*global->buffer,
			global->main_caracter->animation[global->main_caracter->direction
			+ 3], global->main_caracter->x, global->main_caracter->y);
	}
	else
	{
		put_animation_to_image(*global->buffer,
			global->main_caracter->animation[global->main_caracter->direction
			- 1], global->main_caracter->x, global->main_caracter->y);
	}
}

int	render_next_frame(void *global)
{
	t_state			*g;
	static uint64_t	updated_at = 0;

	g = global;
	if (timestamp_in_ms() - updated_at < (uint64_t)(1000 / 60))
		return (0);
	if (g->winning)
	{
		exit_game(global);
		return (1);
	}
	updated_at = timestamp_in_ms();
	fill_pixel_img(*g->buffer, 0xD4D29B);
	render_maps(global);
	render_player(global);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->buffer->img, 0, 0);
	return (0);
}

void	render_maps(t_state *global)
{
	int			i;
	int			j;
	t_entity	*entity;

	i = 0;
	while (i < global->worlds->h)
	{
		j = 0;
		while (j < global->worlds->w)
		{
			entity = global->worlds->table[i][j];
			if (entity->type != -1)
			{
				if (!(entity->type == 3 && global->worlds->collect != 0))
				{
					put_animation_to_image(*global->buffer,
						entity->animation[0], entity->x * 32, entity->y * 32);
				}
			}
			j++;
		}
		i++;
	}
}
