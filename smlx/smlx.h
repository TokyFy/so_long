#ifndef SMLX_H
#define SMLX_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

#define uint unsigned int

typedef struct mlx_image {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    int heigth;
    int width;
} t_mlx_image;

typedef struct animation {
    t_mlx_image **frames;
    int length;
    int cdelay;
    int delay;
    int current;
} t_animation;



void put_pixel_img(t_mlx_image img, unsigned int x, unsigned int y, int color);
unsigned int get_pixel_img(t_mlx_image img, int x, int y);
void put_img_to_img(t_mlx_image dst, t_mlx_image src, int x, int y);
t_mlx_image **load_sprite(void *mlx_ptr, char *xpm, int length);
void fill_pixel_img(t_mlx_image img, int color);
void put_animation_to_image(t_mlx_image img, t_animation *animation, uint x, uint y);

#endif // !SMLX_H
