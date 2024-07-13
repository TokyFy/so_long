/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:15:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/12 14:08:09 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"
#include "smlx/smlx.h"
#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

const char *get_player_run_right(void) {
    static const char *player_run_right =
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

t_mlx_image	***load_all_frame(void *mlx_ptr)
{
	t_mlx_image	***frames;

	frames = malloc(sizeof(t_mlx_image *) * 35);
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
	return (frames);
}
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

static uint64_t	gettimeofday_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

uint64_t	timestamp_in_ms(void)
{
	static uint64_t	created_at;

	if (created_at == 0)
		created_at = gettimeofday_ms();
	return (gettimeofday_ms() - created_at);
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
				put_animation_to_image(*global->buffer, entity->animation[0],
					entity->x * 32, entity->y * 32);
			j++;
		}
		i++;
	}
}

int	render_next_frame(void *global)
{
	t_state			*g;
	static uint64_t	updated_at = 0;

	g = global;
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
	// debug_grid(*g->buffer, 0x9C9868);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->buffer->img, 0, 0);
	return (0);
}

int	on_key_up(int keycode, void *global)
{
	t_state	*g;

	g = global;
	g->main_caracter->idle = 1;
	return (0);
}

int	check_collision(t_state *global, int x, int y)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = (x + 12) / 32;
	y1 = (y) / 32;
	x2 = (x + 31 - 12) / 32;
	y2 = (y + 31) / 32;
	if (global->worlds->table[y1][x1]->type == 1
		|| global->worlds->table[y1][x2]->type == 1
		|| global->worlds->table[y2][x1]->type == 1
		|| global->worlds->table[y2][x2]->type == 1)
	{
		return (0); // Collision detected
	}
	if (global->worlds->table[y1][x1]->type == 2
		|| global->worlds->table[y1][x2]->type == 2
		|| global->worlds->table[y2][x1]->type == 2
		|| global->worlds->table[y2][x2]->type == 2)
	{
		if (global->worlds->table[y1][x1]->type == 2)
			global->worlds->table[y1][x1]->type = -1;
		if (global->worlds->table[y1][x2]->type == 2)
			global->worlds->table[y1][x2]->type = -1;
		if (global->worlds->table[y2][x1]->type == 2)
			global->worlds->table[y2][x1]->type = -1;
		if (global->worlds->table[y2][x2]->type == 2)
			global->worlds->table[y2][x2]->type = -1;
		return (1); // Collision detected
	}
	return (1); // No collision
}

int	on_key_down(int keycode, void *global)
{
	t_state	*g;
	int		factor;
	int		x;
	int		y;

	g = global;
	factor = 8;
	g->main_caracter->idle = 0;
	x = g->main_caracter->x;
	y = g->main_caracter->y;
	if (keycode == 119 || keycode == 122)
	{
		g->main_caracter->direction = 1;
		y = g->main_caracter->y - factor;
	}
	else if (keycode == 115)
	{
		g->main_caracter->direction = 2;
		y = g->main_caracter->y + factor;
	}
	else if (keycode == 97 || keycode == 113)
	{
		g->main_caracter->direction = 3;
		x = g->main_caracter->x - factor;
	}
	else if (keycode == 100)
	{
		g->main_caracter->direction = 4;
		x = g->main_caracter->x + factor;
	}
	if (check_collision(global, x, y))
	{
		g->main_caracter->x = x;
		g->main_caracter->y = y;
	}
	return (0);
}

int	generateRandomNumber(int min, int max)
{
	int	temp;

	if (min > max)
	{
		// Swap min and max if min is greater than max
		temp = min;
		min = max;
		max = temp;
	}
	return ((rand() % (max - min + 1)) + min);
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
	if (entity->type == 0)
	{
		animations[0] = init_animation(global->frame[26
				- (generateRandomNumber(1, 9) == 5)], 60, 1);
	}
	if (entity->type == 2)
	{
		animations[0] = init_animation(global->frame[27
				+ generateRandomNumber(0, 3)], generateRandomNumber(8, 12), 4);
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
	worlds->h = 7;
	worlds->w = 11;
	int _i[7][11] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 2, 0, 2, 0, 2, 0, 2, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1},
		{1, 0, 2, 0, 2, 0, 2, 0, 2, 0, 1},
		{1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};
	worlds->table = malloc(sizeof(t_entity *) * 16);
	global->worlds = worlds;
	i = 0;
	j = 0;
	while (i < global->worlds->h)
	{
		worlds->table[i] = malloc(sizeof(t_entity *) * 32);
		j = 0;
		while (j < global->worlds->w)
		{
			worlds->table[i][j] = malloc(sizeof(t_entity));
			worlds->table[i][j]->type = _i[i][j];
			worlds->table[i][j]->x = j;
			worlds->table[i][j]->y = i;
			init_static_entity(global, worlds->table[i][j]);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_state		global;
	t_mlx_image	buffer;
	int			scale;
	t_entity	player;

	srand(time(NULL));
	scale = 32;
	mlx_ptr = mlx_init();
	global.mlx_ptr = mlx_ptr;
	global.frame = load_all_frame(mlx_ptr);
	init_maps(&global);
	win_ptr = mlx_new_window(mlx_ptr, global.worlds->w * scale, global.worlds->h
			* scale, "- _ -");
	global.win_ptr = win_ptr;
	buffer.width = global.worlds->w * scale;
	buffer.heigth = global.worlds->h * scale;
	buffer.img = mlx_new_image(mlx_ptr, global.worlds->w * scale,
			global.worlds->h * scale);
	buffer.addr = mlx_get_data_addr(buffer.img, &buffer.bits_per_pixel,
			&buffer.line_length, &buffer.endian);
	global.buffer = &buffer;
	player.x = 32;
	player.y = 32;
	player.direction = 1;
	player.idle = 1;
	player.animation = malloc(sizeof(t_animation) * 10);
	player.animation[0] = init_animation(global.frame[0], 8, 6);
	player.animation[1] = init_animation(global.frame[1], 8, 6);
	player.animation[2] = init_animation(global.frame[2], 8, 6);
	player.animation[3] = init_animation(global.frame[3], 8, 6);
	player.animation[4] = init_animation(global.frame[4], 10, 4);
	player.animation[5] = init_animation(global.frame[5], 10, 4);
	player.animation[6] = init_animation(global.frame[6], 10, 4);
	player.animation[7] = init_animation(global.frame[7], 10, 4);
	global.main_caracter = &player;
	mlx_hook(win_ptr, 03, 1L << 1, on_key_up, &global);
	mlx_hook(win_ptr, 02, 1L << 0, on_key_down, &global);
	mlx_loop_hook(mlx_ptr, render_next_frame, &global);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
