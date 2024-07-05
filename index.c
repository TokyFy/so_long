/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:15:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/05 10:20:18 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>

#define WINDOW_WIDTH 32 * 32
#define WINDOW_HEIGHT 32 * 16

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

typedef struct entity {
    int type;
    int x;
    int y;
    int idle;
    int direction;
    t_animation **animation;
} t_entity;

typedef struct state {
    void *mlx_ptr;
    void *win_ptr;
    t_mlx_image *buffer;
    t_entity *main_caracter;
} t_state;

typedef struct maps {
    int w;
    int h;
    t_entity **table;
} t_maps;

void put_pixel_img(t_mlx_image img, unsigned int x, unsigned int y,
                   int color) {
    char *dst;

    if (color == 0xFF000000)
        return;
    if (x > img.width || y > img.heigth)
        return;
    // Fix
    // This asume that the endian is 0
    // This assune that bits_per_pixel is 32
    dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
    *(unsigned int *) dst = color;
}

unsigned int get_pixel_img(t_mlx_image img, int x, int y) {
    return (*(unsigned int *) ((img.addr + (y * img.line_length) + (x
                                                                    * img.bits_per_pixel / 8))));
}

void put_img_to_img(t_mlx_image dst, t_mlx_image src, int x, int y) {
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < src.width) {
        j = 0;
        while (j < src.heigth) {
            put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
            j++;
        }
        i++;
    }
}

void put_animation_to_image(t_mlx_image img, t_animation *animation, uint x,
                            uint y) {
    put_img_to_img(img, *(animation->frames[animation->current]), x, y);
    animation->cdelay--;
    if (animation->cdelay <= 0) {
        animation->current++;
        animation->cdelay = animation->delay;
    }
    if (animation->current > animation->length - 1)
        animation->current = 0;
}

void fill_pixel_img(t_mlx_image img, int color) {
    int y;
    int x;

    y = 0;
    x = 0;
    while (y < img.heigth) {
        x = 0;
        while (x < img.width) {
            put_pixel_img(img, x, y, color);
            x++;
        }
        y++;
    }
}

void debug_grid(t_mlx_image img, int color) {
    int y;
    int x;

    y = 0;
    x = 0;
    while (y < img.heigth) {
        x = 0;
        while (x < img.width) {
            if (x % 32 == 0 || y % 32 == 0)
                put_pixel_img(img, x, y, color);
            x++;
        }
        y++;
    }
}

static uint64_t gettimeofday_ms(void) {
    static struct timeval tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * (uint64_t) 1000) + (tv.tv_usec / 1000));
}

uint64_t timestamp_in_ms(void) {
    static uint64_t created_at;

    if (created_at == 0)
        created_at = gettimeofday_ms();
    return (gettimeofday_ms() - created_at);
}

int render_next_frame(void *global) {
    t_state *g;
    static uint64_t updated_at = 0;
    static int i = 0;
    static int delay = 1;

    g = global;
    if (timestamp_in_ms() - updated_at < (uint64_t) (1000 / 60))
        return (0);
    updated_at = timestamp_in_ms();
    fill_pixel_img(*g->buffer, 0xCACC95);
    debug_grid(*g->buffer, 0x9C9868);
    if (g->main_caracter->idle) {
        put_animation_to_image(*g->buffer,
                               g->main_caracter->animation[g->main_caracter->direction + 3],
                               g->main_caracter->x, g->main_caracter->y);
    } else {
        put_animation_to_image(*g->buffer,
                               g->main_caracter->animation[g->main_caracter->direction - 1],
                               g->main_caracter->x, g->main_caracter->y);
    }
    mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->buffer->img, 0, 0);
    return (0);
}

t_animation *load_sprite(void *mlx_ptr, char **xpm, int length) {
    t_animation *animation;
    t_mlx_image **frames;
    t_mlx_image *image;

    animation = malloc(sizeof(t_animation));
    animation->delay = 6;
    animation->cdelay = 0;
    animation->current = 0;
    animation->length = length;
    frames = malloc(sizeof(t_mlx_image) * length);
    while (animation->current < animation->length) {
        image = malloc(sizeof(t_mlx_image));
        image->img = mlx_xpm_file_to_image(mlx_ptr, xpm[animation->current],
                                           &image->width, &image->heigth);
        image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
                                        &image->line_length, &image->endian);
        frames[animation->current] = image;
        animation->current++;
    }
    animation->frames = frames;
    animation->current = 0;
    return (animation);
}

int on_key_up(int keycode, void *global) {
    t_state *g;

    g = global;
    g->main_caracter->idle = 1;
    return (0);
}

int on_key_down(int keycode, void *global) {
    t_state *g;
    int factor;

    g = global;
    factor = 8;
    g->main_caracter->idle = 0;
    if (keycode == 119) {
        g->main_caracter->direction = 1;
        g->main_caracter->y -= factor;
    } else if (keycode == 115) {
        g->main_caracter->direction = 2;
        g->main_caracter->y += factor;
    } else if (keycode == 97) {
        g->main_caracter->direction = 3;
        g->main_caracter->x -= factor;
    } else if (keycode == 100) {
        g->main_caracter->direction = 4;
        g->main_caracter->x += factor;
    }
    return (0);
}

int main(void) {
    void *mlx_ptr;
    void *win_ptr;
    t_state global;
    t_mlx_image buffer;

    t_maps worlds;
    worlds.h = 16;
    worlds.w = 32;

    int _i[16][32] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    char *run_rigth[] = {
        "./asset/xmp/player/run_right1.xpm",
        "./asset/xmp/player/run_right2.xpm",
        "./asset/xmp/player/run_right3.xpm",
        "./asset/xmp/player/run_right4.xpm",
        "./asset/xmp/player/run_right5.xpm",
        "./asset/xmp/player/run_right6.xpm"
    };
    char *run_left[] = {
        "./asset/xmp/player/run_left1.xpm",
        "./asset/xmp/player/run_left2.xpm",
        "./asset/xmp/player/run_left3.xpm",
        "./asset/xmp/player/run_left4.xpm",
        "./asset/xmp/player/run_left5.xpm",
        "./asset/xmp/player/run_left6.xpm"
    };
    char *run_top[] = {
        "./asset/xmp/player/run_top1.xpm",
        "./asset/xmp/player/run_top2.xpm",
        "./asset/xmp/player/run_top3.xpm",
        "./asset/xmp/player/run_top4.xpm",
        "./asset/xmp/player/run_top5.xpm",
        "./asset/xmp/player/run_top6.xpm"
    };
    char *run_bottom[] = {
        "./asset/xmp/player/run_bottom1.xpm",
        "./asset/xmp/player/run_bottom2.xpm",
        "./asset/xmp/player/run_bottom3.xpm",
        "./asset/xmp/player/run_bottom4.xpm",
        "./asset/xmp/player/run_bottom5.xpm",
        "./asset/xmp/player/run_bottom6.xpm"
    };
    t_entity player;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "- _ -");
    buffer.width = WINDOW_WIDTH;
    buffer.heigth = WINDOW_HEIGHT;
    buffer.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    buffer.addr = mlx_get_data_addr(buffer.img, &buffer.bits_per_pixel,
                                    &buffer.line_length, &buffer.endian);
    global.win_ptr = win_ptr;
    global.mlx_ptr = mlx_ptr;
    global.buffer = &buffer;
    // HERE
    char *idle_rigth[] = {
        "./asset/xmp/player/idle_right1.xpm",
        "./asset/xmp/player/idle_right2.xpm",
        "./asset/xmp/player/idle_right3.xpm",
        "./asset/xmp/player/idle_right4.xpm",
    };
    char *idle_left[] = {
        "./asset/xmp/player/idle_left1.xpm",
        "./asset/xmp/player/idle_left2.xpm",
        "./asset/xmp/player/idle_left3.xpm",
        "./asset/xmp/player/idle_left4.xpm",
    };
    char *idle_top[] = {
        "./asset/xmp/player/idle_top1.xpm",
        "./asset/xmp/player/idle_top2.xpm",
        "./asset/xmp/player/idle_top3.xpm",
        "./asset/xmp/player/idle_top4.xpm",
    };
    char *idle_bottom[] = {
        "./asset/xmp/player/idle_bottom1.xpm",
        "./asset/xmp/player/idle_bottom2.xpm",
        "./asset/xmp/player/idle_bottom3.xpm",
        "./asset/xmp/player/idle_bottom4.xpm",
    };

    player.x = 0;
    player.y = 0;
    player.direction = 2;
    player.idle = 0;
    player.animation = calloc(sizeof(t_animation *), 10);
    global.main_caracter = &player;
    global.main_caracter->animation[0] = load_sprite(mlx_ptr, run_top, 6);
    global.main_caracter->animation[1] = load_sprite(mlx_ptr, run_bottom, 6);
    global.main_caracter->animation[2] = load_sprite(mlx_ptr, run_left, 6);
    global.main_caracter->animation[3] = load_sprite(mlx_ptr, run_rigth, 6);
    global.main_caracter->animation[4] = load_sprite(mlx_ptr, idle_top, 4);
    global.main_caracter->animation[5] = load_sprite(mlx_ptr, idle_bottom, 4);
    global.main_caracter->animation[6] = load_sprite(mlx_ptr, idle_left, 4);
    global.main_caracter->animation[7] = load_sprite(mlx_ptr, idle_rigth, 4);

    mlx_hook(win_ptr, 03, 1L << 1, on_key_up, &global);
    mlx_hook(win_ptr, 02, 1L << 0, on_key_down, &global);
    mlx_loop_hook(mlx_ptr, render_next_frame, &global);
    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}
