/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:30:53 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/24 15:50:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

const char	*get_player_run_right(void);
const char	*get_player_run_left(void);
const char	*get_player_run_top(void);
const char	*get_player_run_bottom(void);
const char	*get_player_idle_right(void);

const char	*get_player_idle_right(void);
const char	*get_player_idle_left(void);
const char	*get_player_idle_top(void);
const char	*get_player_idle_bottom(void);

const char	*get_wall_left(void);
const char	*get_wall_top(void);
const char	*get_wall_bottom(void);
const char	*get_wall_right(void);

const char	*get_wall_top_left(void);
const char	*get_wall_bottom_left(void);
const char	*get_wall_top_right(void);
const char	*get_wall_bottom_right(void);

const char	*get_obstacle_1(void);
const char	*get_obstacle_2(void);
const char	*get_obstacle_3(void);
const char	*get_obstacle_4(void);
const char	*get_obstacle_5(void);

const char	*get_obstacle_6(void);
const char	*get_obstacle_7(void);
const char	*get_obstacle_8(void);
const char	*get_obstacle_9(void);
const char	*get_obstacle_10(void);
const char	*get_obstacle_11(void);

const char	*get_ground_1(void);
const char	*get_ground_2(void);

const char	*get_coin_1(void);
const char	*get_coin_2(void);
const char	*get_coin_3(void);
const char	*get_coin_4(void);

const char	*get_temporary_obstacle(void);
const char	*get_exit(void);

# define PLAYER_RUN_RIGHT get_player_run_right
# define PLAYER_RUN_LEFT get_player_run_left
# define PLAYER_RUN_TOP get_player_run_top
# define PLAYER_RUN_BOTTOM get_player_run_bottom

# define PLAYER_IDLE_RIGHT get_player_idle_right
# define PLAYER_IDLE_LEFT get_player_idle_left
# define PLAYER_IDLE_TOP get_player_idle_top
# define PLAYER_IDLE_BOTTOM get_player_idle_bottom

# define WALL_LEFT get_wall_left
# define WALL_TOP get_wall_top
# define WALL_BOTTOM get_wall_bottom
# define WALL_RIGHT get_wall_right

# define WALL_TOP_LEFT get_wall_top_left
# define WALL_BOTTOM_LEFT get_wall_bottom_left
# define WALL_TOP_RIGHT get_wall_top_right
# define WALL_BOTTOM_RIGHT get_wall_bottom_right

# define OBSTACLE_1 get_obstacle_1
# define OBSTACLE_2 get_obstacle_2
# define OBSTACLE_3 get_obstacle_3
# define OBSTACLE_4 get_obstacle_4
# define OBSTACLE_5 get_obstacle_5
# define OBSTACLE_6 get_obstacle_6
# define OBSTACLE_7 get_obstacle_7
# define OBSTACLE_8 get_obstacle_8
# define OBSTACLE_9 get_obstacle_9
# define OBSTACLE_10 get_obstacle_10
# define OBSTACLE_11 get_obstacle_11

# define GROUND_1 get_ground_1
# define GROUND_2 get_ground_2

# define COIN_1 get_coin_1
# define COIN_2 get_coin_2
# define COIN_3 get_coin_3
# define COIN_4 get_coin_4

# define TEMPORARY_OBSTACLE get_temporary_obstacle
# define EXIT get_exit

#endif
