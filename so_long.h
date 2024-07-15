#ifndef SO_LONG_H
#define SO_LONG_H

#include "smlx/smlx.h"

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
