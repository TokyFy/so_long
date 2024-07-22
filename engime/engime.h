/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engime.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:06:00 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/22 13:14:44 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGIME_H
#define ENGIME_H

#include <stdint.h>
#include <sys/time.h>
#include "../smlx/smlx.h"
#include "../so_long.h"

int	check_collision(t_state *global, int x, int y);
static uint64_t	gettimeofday_ms(void);
uint64_t	timestamp_in_ms(void);

t_mlx_image	***load_all_frame(void *mlx_ptr);
int	render_next_frame(void *global);
void	render_maps(t_state *global);
void	init_maps(t_state *global , char* ber_path);

int	on_key_up(int keycode, void *global);
int	on_key_down(int keycode, void *global);

int ** fill_map_from_ber(t_list* line , int width , int heigh);
int ** ber_file_parser(char *path , int *w , int *h);

int	generateRandomNumber(int min, int max);
void print_arr(int **arr , int w , int h);

void free_all_frame(t_state *global);
void free_2d_int(int **arr, int h);

#endif
