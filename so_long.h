/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:52:00 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/16 14:42:49 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "smlx/smlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define SCALE 32

typedef struct entity {
    int type;
    int x;
    int y;
    int idle;
    int direction;
    t_animation **animation;
    int c_animation;
} t_entity;

typedef struct maps {
    int w;
    int h;
    t_entity ***table;
    int collect;
} t_maps;

typedef struct state {
    void *mlx_ptr;
    void *win_ptr;
    t_mlx_image *buffer;
    t_entity *main_caracter;
    t_mlx_image ***frame;
    t_maps *worlds;
} t_state;

int ** ber_file_parser(char *path , int *w , int *h);

#endif // !SO_LONG_H
