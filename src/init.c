/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:21:36 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/23 15:22:09 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../engime/engime.h"
#include "../so_long.h"

void	init_player(t_state *global)
{
	t_entity	*player;

	player = malloc(sizeof(t_entity));
	player->x = 32;
	player->y = 32;
	player->direction = 1;
	player->idle = 1;
	player->animation = malloc(sizeof(t_animation) * 10);
	player->animation[0] = init_animation(global->frame[0], 8, 6);
	player->animation[1] = init_animation(global->frame[1], 8, 6);
	player->animation[2] = init_animation(global->frame[2], 8, 6);
	player->animation[3] = init_animation(global->frame[3], 8, 6);
	player->animation[4] = init_animation(global->frame[4], 10, 4);
	player->animation[5] = init_animation(global->frame[5], 10, 4);
	player->animation[6] = init_animation(global->frame[6], 10, 4);
	player->animation[7] = init_animation(global->frame[7], 10, 4);
	player->c_animation = 8;
	global->main_caracter = player;
}

void	init_global(t_state *global)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	global->buffer = NULL;
	global->mlx_ptr = NULL;
	global->win_ptr = NULL;
	global->main_caracter = NULL;
	global->frame = NULL;
	global->worlds = NULL;
	global->winning = 0;
	global->mlx_ptr = mlx_ptr;
	global->frame = load_all_frame(mlx_ptr);
}

void	init_windows(t_state *global)
{
	void		*win_ptr;
	t_mlx_image	*buffer;

	buffer = malloc(sizeof(t_mlx_image));
	win_ptr = mlx_new_window(global->mlx_ptr, global->worlds->w * SCALE,
			global->worlds->h * SCALE, "- _ -");
	global->win_ptr = win_ptr;
	buffer->width = global->worlds->w * SCALE;
	buffer->heigth = global->worlds->h * SCALE;
	buffer->img = mlx_new_image(global->mlx_ptr, global->worlds->w * SCALE,
			global->worlds->h * SCALE);
	buffer->addr = mlx_get_data_addr(buffer->img, &(buffer->bits_per_pixel),
			&(buffer->line_length), &(buffer->endian));
	global->buffer = buffer;
}
