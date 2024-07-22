/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:59:14 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/19 15:22:22 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../smlx/smlx.h"
#include "engime.h"
#include <stdlib.h>
#include "../so_long.h"

const char *get_player_run_right(void) {
    const char *player_run_right =
        "./asset/xmp/player/run_right1.xpm," \
        "./asset/xmp/player/run_right2.xpm," \
        "./asset/xmp/player/run_right3.xpm," \
        "./asset/xmp/player/run_right4.xpm," \
        "./asset/xmp/player/run_right5.xpm," \
        "./asset/xmp/player/run_right6.xpm";

    return player_run_right;
}

#define PLAYER_RUN_RIGHT get_player_run_right()

#define PLAYER_RUN_LEFT                 \
	"./asset/xmp/player/run_left1.xpm," \
	"./asset/xmp/player/run_left2.xpm," \
	"./asset/xmp/player/run_left3.xpm," \
	"./asset/xmp/player/run_left4.xpm," \
	"./asset/xmp/player/run_left5.xpm," \
	"./asset/xmp/player/run_left6.xpm"

#define PLAYER_RUN_TOP                 \
	"./asset/xmp/player/run_top1.xpm," \
	"./asset/xmp/player/run_top2.xpm," \
	"./asset/xmp/player/run_top3.xpm," \
	"./asset/xmp/player/run_top4.xpm," \
	"./asset/xmp/player/run_top5.xpm," \
	"./asset/xmp/player/run_top6.xpm"

#define PLAYER_RUN_BOTTOM                 \
	"./asset/xmp/player/run_bottom1.xpm," \
	"./asset/xmp/player/run_bottom2.xpm," \
	"./asset/xmp/player/run_bottom3.xpm," \
	"./asset/xmp/player/run_bottom4.xpm," \
	"./asset/xmp/player/run_bottom5.xpm," \
	"./asset/xmp/player/run_bottom6.xpm"

#define PLAYER_IDLE_RIGHT                 \
	"./asset/xmp/player/idle_right1.xpm," \
	"./asset/xmp/player/idle_right2.xpm," \
	"./asset/xmp/player/idle_right3.xpm," \
	"./asset/xmp/player/idle_right4.xpm"

#define PLAYER_IDLE_LEFT                 \
	"./asset/xmp/player/idle_left1.xpm," \
	"./asset/xmp/player/idle_left2.xpm," \
	"./asset/xmp/player/idle_left3.xpm," \
	"./asset/xmp/player/idle_left4.xpm"

#define PLAYER_IDLE_TOP                 \
	"./asset/xmp/player/idle_top1.xpm," \
	"./asset/xmp/player/idle_top2.xpm," \
	"./asset/xmp/player/idle_top3.xpm," \
	"./asset/xmp/player/idle_top4.xpm"

#define PLAYER_IDLE_BOTTOM                 \
	"./asset/xmp/player/idle_bottom1.xpm," \
	"./asset/xmp/player/idle_bottom2.xpm," \
	"./asset/xmp/player/idle_bottom3.xpm," \
	"./asset/xmp/player/idle_bottom4.xpm"

#define WALL_LEFT "./asset/xmp/wall/wall_left.xpm"
#define WALL_TOP "./asset/xmp/wall/wall_top.xpm"
#define WALL_BOTTOM "./asset/xmp/wall/wall_bottom.xpm"
#define WALL_RIGHT "./asset/xmp/wall/wall_right.xpm"
#define WALL_TOP_LEFT "./asset/xmp/wall/wall_top_left.xpm"
#define WALL_BOTTOM_LEFT "./asset/xmp/wall/wall_bottom_left.xpm"
#define WALL_TOP_RIGHT "./asset/xmp/wall/wall_top_right.xpm"
#define WALL_BOTTOM_RIGHT "./asset/xmp/wall/wall_bottom_right.xpm"

#define OBSTACLE_1 "asset/xmp/obst/obs1.xpm"
#define OBSTACLE_2 "asset/xmp/obst/obs2.xpm"
#define OBSTACLE_3 "asset/xmp/obst/obs3.xpm"
#define OBSTACLE_4 "asset/xmp/obst/obs4.xpm"
#define OBSTACLE_5 "asset/xmp/obst/obs5.xpm"
#define OBSTACLE_6 "asset/xmp/obst/obs6.xpm"
#define OBSTACLE_7 "asset/xmp/obst/obs7.xpm"
#define OBSTACLE_8 "asset/xmp/obst/obs8.xpm"
#define OBSTACLE_9 "asset/xmp/obst/obs9.xpm"
#define OBSTACLE_10 "asset/xmp/obst/obs10.xpm"
#define OBSTACLE_11 "asset/xmp/obst/obs11.xpm"

#define GROUND_1 "./asset/xmp/ground/ground_1.xpm"
#define GROUND_2 "./asset/xmp/ground/ground_2.xpm"

#define COIN_1                    \
	"./asset/xmp/props/key1.xpm," \
	"./asset/xmp/props/key2.xpm," \
	"./asset/xmp/props/key3.xpm," \
	"./asset/xmp/props/key4.xpm"

#define COIN_2                       \
	"./asset/xmp/props/potion1.xpm," \
	"./asset/xmp/props/potion2.xpm," \
	"./asset/xmp/props/potion3.xpm," \
	"./asset/xmp/props/potion4.xpm"

#define COIN_3                      \
	"./asset/xmp/props/heart1.xpm," \
	"./asset/xmp/props/heart2.xpm," \
	"./asset/xmp/props/heart3.xpm," \
	"./asset/xmp/props/heart4.xpm"

#define COIN_4                     \
	"./asset/xmp/props/food1.xpm," \
	"./asset/xmp/props/food2.xpm," \
	"./asset/xmp/props/food3.xpm," \
	"./asset/xmp/props/food4.xpm"

#define TEMPORARY_OBSTACLE "./asset/xmp/wall.xpm"
#define EXIT "./asset/xmp/exit.xpm"


t_mlx_image	***load_all_frame(void *mlx_ptr)
{
    t_mlx_image	***frames;

    frames = malloc(sizeof(t_mlx_image *) * 32);
    frames[0] = load_sprite(mlx_ptr, PLAYER_RUN_TOP, 6);
    frames[1] = load_sprite(mlx_ptr, PLAYER_RUN_BOTTOM, 6);
    frames[2] = load_sprite(mlx_ptr, PLAYER_RUN_LEFT, 6);
    frames[3] = load_sprite(mlx_ptr, PLAYER_RUN_RIGHT, 6);
    frames[4] = load_sprite(mlx_ptr, PLAYER_IDLE_TOP, 4);
    frames[5] = load_sprite(mlx_ptr, PLAYER_IDLE_BOTTOM, 4);
    frames[6] = load_sprite(mlx_ptr, PLAYER_IDLE_LEFT, 4);
    frames[7] = load_sprite(mlx_ptr, PLAYER_IDLE_RIGHT, 4);
    frames[8] = load_sprite(mlx_ptr, WALL_TOP, 1);
    frames[9] = load_sprite(mlx_ptr, WALL_BOTTOM, 1);
    frames[10] = load_sprite(mlx_ptr, WALL_LEFT, 1);
    frames[11] = load_sprite(mlx_ptr, WALL_RIGHT, 1);
    frames[12] = load_sprite(mlx_ptr, WALL_TOP_LEFT, 1);
    frames[13] = load_sprite(mlx_ptr, WALL_TOP_RIGHT, 1);
    frames[14] = load_sprite(mlx_ptr, WALL_BOTTOM_LEFT, 1);
    frames[15] = load_sprite(mlx_ptr, WALL_BOTTOM_RIGHT, 1);
    frames[16] = load_sprite(mlx_ptr, TEMPORARY_OBSTACLE, 1);
    frames[17] = load_sprite(mlx_ptr, OBSTACLE_1, 1);
    frames[18] = load_sprite(mlx_ptr, OBSTACLE_2, 1);
    frames[19] = load_sprite(mlx_ptr, OBSTACLE_3, 1);
    frames[20] = load_sprite(mlx_ptr, OBSTACLE_4, 1);
    frames[21] = load_sprite(mlx_ptr, OBSTACLE_5, 1);
    frames[22] = load_sprite(mlx_ptr, OBSTACLE_6, 1);
    frames[23] = load_sprite(mlx_ptr, OBSTACLE_7, 1);
    frames[24] = load_sprite(mlx_ptr, OBSTACLE_8, 1);
    frames[25] = load_sprite(mlx_ptr, GROUND_1, 1);
    frames[26] = load_sprite(mlx_ptr, GROUND_2, 1);
    frames[27] = load_sprite(mlx_ptr, COIN_1, 4);
    frames[28] = load_sprite(mlx_ptr, COIN_2, 4);
    frames[29] = load_sprite(mlx_ptr, COIN_3, 4);
    frames[30] = load_sprite(mlx_ptr, COIN_4, 4);
    frames[31] = load_sprite(mlx_ptr, EXIT, 1);
    return (frames);
}

void free_frame(t_state *global , t_mlx_image **frame , int length)
{
  int i = 0;

  while(i < length)
  {
    destroy_image(global , frame[i]);
    i++;
  }

  free(frame);
}

void free_frame_set(t_state *global , int start  , int slen , int flen)
{
  int i = 0;
  while (i < slen) {
    free_frame(global , global->frame[i + start], flen);
    i++;
  }
}

void free_all_frame(t_state *global)
{
  free_frame_set(global , 0 , 4, 6);
  free_frame_set(global , 4, 4, 4);
  free_frame_set(global , 8, 19, 1);
  free_frame_set(global , 27, 4, 4);
  free_frame_set(global , 31, 1, 1);
  free(global->frame);
}

int	render_next_frame(void *global)
{
	t_state			*g;
	static uint64_t	updated_at = 0;

	g = global;

	if(g->winning)
  {
		exit_game(global);
		return (1);
  }

	if (timestamp_in_ms() - updated_at < (uint64_t)(1000 / 60))
		return (0);
	updated_at = timestamp_in_ms();
	fill_pixel_img(*g->buffer, 0xD4D29B);
	render_maps(global);
	if (g->main_caracter->idle)
	{
		put_animation_to_image(*g->buffer,
			g->main_caracter->animation[g->main_caracter->direction + 3],
			g->main_caracter->x, g->main_caracter->y);
	}
	else
	{
		put_animation_to_image(*g->buffer,
			g->main_caracter->animation[g->main_caracter->direction - 1],
			g->main_caracter->x, g->main_caracter->y);
	}

	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->buffer->img, 0, 0);
	return 0;
}

void	render_maps(t_state *global)
{
	int			i;
	int			j;
	t_entity	*entity;

	i = 0;
	j = 0;
	while (i < global->worlds->h)
	{
		j = 0;
		while (j < global->worlds->w)
		{
			entity = global->worlds->table[i][j];
			if (entity->type != -1)
				if(!(entity->type == 3 && global->worlds->collect != 0))
				{
					put_animation_to_image(*global->buffer, entity->animation[0],
						entity->x * 32, entity->y * 32);
				}
			j++;
		}
		i++;
	}
}

