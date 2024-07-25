/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engime.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:06:00 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/24 15:38:23 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGIME_H
# define ENGIME_H

# include "../asset/src/assets.h"
# include "../smlx/smlx.h"
# include "../so_long.h"
# include <fcntl.h>
# include <stdint.h>
# include <sys/time.h>
# include <unistd.h>

int			check_collision(t_state *global, int x, int y);
uint64_t	gettimeofday_ms(void);
uint64_t	timestamp_in_ms(void);

t_mlx_image	***load_all_frame(void *mlx_ptr);
int			render_next_frame(void *global);
void		render_maps(t_state *global);
void		init_maps(t_state *global, char *ber_path);

int			on_key_up(int keycode, void *global);
int			on_key_down(int keycode, void *global);

int			**fill_map_from_ber(t_list *line, int width, int heigh);
int			**ber_file_parser(char *path, int *w, int *h);

int			ft_random(int min, int max);
void		print_arr(int **arr, int w, int h);

void		free_all_frame(t_state *global);
void		free_2d_int(int **arr, int h);

void		fill_ceil(int *ceil, char content);
void		reachable_by_player(int x, int y, int **arr);
int			is_all_reachable(int rows, int cols, int **array);
int			have_only_one_player_exit(int row, int cols, int **array);
int			have_at_least_one_collectible(int row, int col, int **array);

int			valid_map_line(char *str);
int			valid_wall(int **table, int width, int heigh);
int			verify_line(char *str, int *w, int *h);
void		init_zero(void *ptr1, void *ptr2, void *ptr3, void *ptr4);
void		init_static_entity(t_state *global, t_entity *entity);

#endif
