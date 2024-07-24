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

#include "../smlx/smlx.h"
#include "../so_long.h"
#include "engime.h"
#include <stdlib.h>



const char *get_wall_left(void) {
    const char *wall_left = "./asset/xmp/wall/wall_left.xpm";
    return wall_left;
}
#define WALL_LEFT get_wall_left

const char *get_wall_top(void) {
    const char *wall_top = "./asset/xmp/wall/wall_top.xpm";
    return wall_top;
}
#define WALL_TOP get_wall_top

const char *get_wall_bottom(void) {
    const char *wall_bottom = "./asset/xmp/wall/wall_bottom.xpm";
    return wall_bottom;
}
#define WALL_BOTTOM get_wall_bottom

const char *get_wall_right(void) {
    const char *wall_right = "./asset/xmp/wall/wall_right.xpm";
    return wall_right;
}
#define WALL_RIGHT get_wall_right

const char *get_wall_top_left(void) {
    const char *wall_top_left = "./asset/xmp/wall/wall_top_left.xpm";
    return wall_top_left;
}
#define WALL_TOP_LEFT get_wall_top_left

const char *get_wall_bottom_left(void) {
    const char *wall_bottom_left = "./asset/xmp/wall/wall_bottom_left.xpm";
    return wall_bottom_left;
}
#define WALL_BOTTOM_LEFT get_wall_bottom_left

const char *get_wall_top_right(void) {
    const char *wall_top_right = "./asset/xmp/wall/wall_top_right.xpm";
    return wall_top_right;
}
#define WALL_TOP_RIGHT get_wall_top_right

const char *get_wall_bottom_right(void) {
    const char *wall_bottom_right = "./asset/xmp/wall/wall_bottom_right.xpm";
    return wall_bottom_right;
}
#define WALL_BOTTOM_RIGHT get_wall_bottom_right

const char *get_obstacle_1(void) {
    const char *obstacle_1 = "asset/xmp/obst/obs1.xpm";
    return obstacle_1;
}
#define OBSTACLE_1 get_obstacle_1

const char *get_obstacle_2(void) {
    const char *obstacle_2 = "asset/xmp/obst/obs2.xpm";
    return obstacle_2;
}
#define OBSTACLE_2 get_obstacle_2

const char *get_obstacle_3(void) {
    const char *obstacle_3 = "asset/xmp/obst/obs3.xpm";
    return obstacle_3;
}
#define OBSTACLE_3 get_obstacle_3

const char *get_obstacle_4(void) {
    const char *obstacle_4 = "asset/xmp/obst/obs4.xpm";
    return obstacle_4;
}
#define OBSTACLE_4 get_obstacle_4

const char *get_obstacle_5(void) {
    const char *obstacle_5 = "asset/xmp/obst/obs5.xpm";
    return obstacle_5;
}
#define OBSTACLE_5 get_obstacle_5

const char *get_obstacle_6(void) {
    const char *obstacle_6 = "asset/xmp/obst/obs6.xpm";
    return obstacle_6;
}
#define OBSTACLE_6 get_obstacle_6

const char *get_obstacle_7(void) {
    const char *obstacle_7 = "asset/xmp/obst/obs7.xpm";
    return obstacle_7;
}
#define OBSTACLE_7 get_obstacle_7

const char *get_obstacle_8(void) {
    const char *obstacle_8 = "asset/xmp/obst/obs8.xpm";
    return obstacle_8;
}
#define OBSTACLE_8 get_obstacle_8

const char *get_obstacle_9(void) {
    const char *obstacle_9 = "asset/xmp/obst/obs9.xpm";
    return obstacle_9;
}
#define OBSTACLE_9 get_obstacle_9

const char *get_obstacle_10(void) {
    const char *obstacle_10 = "asset/xmp/obst/obs10.xpm";
    return obstacle_10;
}
#define OBSTACLE_10 get_obstacle_10

const char *get_obstacle_11(void) {
    const char *obstacle_11 = "asset/xmp/obst/obs11.xpm";
    return obstacle_11;
}
#define OBSTACLE_11 get_obstacle_11

const char *get_ground_1(void) {
    const char *ground_1 = "./asset/xmp/ground/ground_1.xpm";
    return ground_1;
}

#define GROUND_1 get_ground_1

const char *get_ground_2(void) {
    const char *ground_2 = "./asset/xmp/ground/ground_2.xpm";
    return ground_2;
}

#define GROUND_2 get_ground_2


const char	*get_coin_1(void)
{
	const char *coin_1 = "./asset/xmp/props/key1.xpm,"
							"./asset/xmp/props/key2.xpm,"
							"./asset/xmp/props/key3.xpm,"
							"./asset/xmp/props/key4.xpm";
	return (coin_1);
}

#define COIN_1 get_coin_1

const char	*get_coin_2(void)
{
	const char *coin_2 = "./asset/xmp/props/potion1.xpm,"
							"./asset/xmp/props/potion2.xpm,"
							"./asset/xmp/props/potion3.xpm,"
							"./asset/xmp/props/potion4.xpm";
	return (coin_2);
}

#define COIN_2 get_coin_2

const char	*get_coin_3(void)
{
	const char *coin_3 = "./asset/xmp/props/heart1.xpm,"
							"./asset/xmp/props/heart2.xpm,"
							"./asset/xmp/props/heart3.xpm,"
							"./asset/xmp/props/heart4.xpm";
	return (coin_3);
}

#define COIN_3 get_coin_3

const char	*get_coin_4(void)
{
	const char *coin_4 = "./asset/xmp/props/food1.xpm,"
							"./asset/xmp/props/food2.xpm,"
							"./asset/xmp/props/food3.xpm,"
							"./asset/xmp/props/food4.xpm";
	return (coin_4);
}

#define COIN_4 get_coin_4

const char *get_temporary_obstacle(void) {
    const char *temporary_obstacle = "./asset/xmp/wall.xpm";
    return temporary_obstacle;
}
#define TEMPORARY_OBSTACLE get_temporary_obstacle

const char *get_exit(void) {
    const char *exit = "./asset/xmp/exit.xpm";
    return exit;
}
#define EXIT get_exit


t_mlx_image	***load_all_frame(void *mlx_ptr)
{
	t_mlx_image	***frames;

	frames = malloc(sizeof(t_mlx_image *) * 32);
	frames[0] = load_sprite(mlx_ptr, PLAYER_RUN_TOP(), 6);
	frames[1] = load_sprite(mlx_ptr, PLAYER_RUN_BOTTOM(), 6);
	frames[2] = load_sprite(mlx_ptr, PLAYER_RUN_LEFT(), 6);
	frames[3] = load_sprite(mlx_ptr, PLAYER_RUN_RIGHT(), 6);
	frames[4] = load_sprite(mlx_ptr, PLAYER_IDLE_TOP(), 4);
	frames[5] = load_sprite(mlx_ptr, PLAYER_IDLE_BOTTOM(), 4);
	frames[6] = load_sprite(mlx_ptr, PLAYER_IDLE_LEFT(), 4);
	frames[7] = load_sprite(mlx_ptr, PLAYER_IDLE_RIGHT(), 4);
	frames[8] = load_sprite(mlx_ptr, WALL_TOP(), 1);
	frames[9] = load_sprite(mlx_ptr, WALL_BOTTOM(), 1);
	frames[10] = load_sprite(mlx_ptr, WALL_LEFT(), 1);
	frames[11] = load_sprite(mlx_ptr, WALL_RIGHT(), 1);
	frames[12] = load_sprite(mlx_ptr, WALL_TOP_LEFT(), 1);
	frames[13] = load_sprite(mlx_ptr, WALL_TOP_RIGHT(), 1);
	frames[14] = load_sprite(mlx_ptr, WALL_BOTTOM_LEFT(), 1);
	frames[15] = load_sprite(mlx_ptr, WALL_BOTTOM_RIGHT(), 1);
	frames[16] = load_sprite(mlx_ptr, TEMPORARY_OBSTACLE(), 1);
	frames[17] = load_sprite(mlx_ptr, OBSTACLE_1(), 1);
	frames[18] = load_sprite(mlx_ptr, OBSTACLE_2(), 1);
	frames[19] = load_sprite(mlx_ptr, OBSTACLE_3(), 1);
	frames[20] = load_sprite(mlx_ptr, OBSTACLE_4(), 1);
	frames[21] = load_sprite(mlx_ptr, OBSTACLE_5(), 1);
	frames[22] = load_sprite(mlx_ptr, OBSTACLE_6(), 1);
	frames[23] = load_sprite(mlx_ptr, OBSTACLE_7(), 1);
	frames[24] = load_sprite(mlx_ptr, OBSTACLE_8(), 1);
	frames[25] = load_sprite(mlx_ptr, GROUND_1(), 1);
	frames[26] = load_sprite(mlx_ptr, GROUND_2(), 1);
	frames[27] = load_sprite(mlx_ptr, COIN_1(), 4);
	frames[28] = load_sprite(mlx_ptr, COIN_2(), 4);
	frames[29] = load_sprite(mlx_ptr, COIN_3(), 4);
	frames[30] = load_sprite(mlx_ptr, COIN_4(), 4);
	frames[31] = load_sprite(mlx_ptr, EXIT(), 1);
	return (frames);
}

void	free_frame(t_state *global, t_mlx_image **frame, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		destroy_image(global, frame[i]);
		i++;
	}
	free(frame);
}

void	free_frame_set(t_state *global, int start, int slen, int flen)
{
	int	i;

	i = 0;
	while (i < slen)
	{
		free_frame(global, global->frame[i + start], flen);
		i++;
	}
}

void	free_all_frame(t_state *global)
{
	free_frame_set(global, 0, 4, 6);
	free_frame_set(global, 4, 4, 4);
	free_frame_set(global, 8, 19, 1);
	free_frame_set(global, 27, 4, 4);
	free_frame_set(global, 31, 1, 1);
	free(global->frame);
}

int	render_next_frame(void *global)
{
	t_state			*g;
	static uint64_t	updated_at = 0;

	g = global;
	if (g->winning)
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
	return (0);
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
				if (!(entity->type == 3 && global->worlds->collect != 0))
				{
					put_animation_to_image(*global->buffer,
						entity->animation[0], entity->x * 32, entity->y * 32);
				}
			j++;
		}
		i++;
	}
}
