#include "engime.h"

void	load_player_frames(t_mlx_image ***frames, void *mlx_ptr)
{
	if (frames == NULL)
		return ;
	frames[0] = load_sprite(mlx_ptr, PLAYER_RUN_TOP(), 6);
	frames[1] = load_sprite(mlx_ptr, PLAYER_RUN_BOTTOM(), 6);
	frames[2] = load_sprite(mlx_ptr, PLAYER_RUN_LEFT(), 6);
	frames[3] = load_sprite(mlx_ptr, PLAYER_RUN_RIGHT(), 6);
	frames[4] = load_sprite(mlx_ptr, PLAYER_IDLE_TOP(), 4);
	frames[5] = load_sprite(mlx_ptr, PLAYER_IDLE_BOTTOM(), 4);
	frames[6] = load_sprite(mlx_ptr, PLAYER_IDLE_LEFT(), 4);
	frames[7] = load_sprite(mlx_ptr, PLAYER_IDLE_RIGHT(), 4);
}

void	load_wall_frames(t_mlx_image ***frames, void *mlx_ptr)
{
	if (frames == NULL)
		return ;
	frames[8] = load_sprite(mlx_ptr, WALL_TOP(), 1);
	frames[9] = load_sprite(mlx_ptr, WALL_BOTTOM(), 1);
	frames[10] = load_sprite(mlx_ptr, WALL_LEFT(), 1);
	frames[11] = load_sprite(mlx_ptr, WALL_RIGHT(), 1);
	frames[12] = load_sprite(mlx_ptr, WALL_TOP_LEFT(), 1);
	frames[13] = load_sprite(mlx_ptr, WALL_TOP_RIGHT(), 1);
	frames[14] = load_sprite(mlx_ptr, WALL_BOTTOM_LEFT(), 1);
	frames[15] = load_sprite(mlx_ptr, WALL_BOTTOM_RIGHT(), 1);
}

void	load_obstacle_frames(t_mlx_image ***frames, void *mlx_ptr)
{
	if (frames == NULL)
		return ;
	frames[16] = load_sprite(mlx_ptr, TEMPORARY_OBSTACLE(), 1);
	frames[17] = load_sprite(mlx_ptr, OBSTACLE_1(), 1);
	frames[18] = load_sprite(mlx_ptr, OBSTACLE_2(), 1);
	frames[19] = load_sprite(mlx_ptr, OBSTACLE_3(), 1);
	frames[20] = load_sprite(mlx_ptr, OBSTACLE_4(), 1);
	frames[21] = load_sprite(mlx_ptr, OBSTACLE_5(), 1);
	frames[22] = load_sprite(mlx_ptr, OBSTACLE_6(), 1);
	frames[23] = load_sprite(mlx_ptr, OBSTACLE_7(), 1);
	frames[24] = load_sprite(mlx_ptr, OBSTACLE_8(), 1);
}

void	load_misc_frames(t_mlx_image ***frames, void *mlx_ptr)
{
	if (frames == NULL)
		return ;
	frames[25] = load_sprite(mlx_ptr, GROUND_1(), 1);
	frames[26] = load_sprite(mlx_ptr, GROUND_2(), 1);
	frames[27] = load_sprite(mlx_ptr, COIN_1(), 4);
	frames[28] = load_sprite(mlx_ptr, COIN_2(), 4);
	frames[29] = load_sprite(mlx_ptr, COIN_3(), 4);
	frames[30] = load_sprite(mlx_ptr, COIN_4(), 4);
	frames[31] = load_sprite(mlx_ptr, EXIT(), 1);
}

t_mlx_image	***load_all_frame(void *mlx_ptr)
{
	t_mlx_image	***frames;

	frames = malloc(sizeof(t_mlx_image *) * 32);
	load_player_frames(frames, mlx_ptr);
	load_wall_frames(frames, mlx_ptr);
	load_obstacle_frames(frames, mlx_ptr);
	load_misc_frames(frames, mlx_ptr);
	return (frames);
}
