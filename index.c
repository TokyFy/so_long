/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:15:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/09 14:44:53 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "smlx/smlx.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>

#define WINDOW_WIDTH 32 * 32
#define WINDOW_HEIGHT 32 * 16

#define PLAYER_RUN_RIGHT "./asset/xmp/player/run_right1.xpm,"\
						 "./asset/xmp/player/run_right2.xpm,"\
						 "./asset/xmp/player/run_right3.xpm,"\
						 "./asset/xmp/player/run_right4.xpm,"\
						 "./asset/xmp/player/run_right5.xpm,"\
						 "./asset/xmp/player/run_right6.xpm"

#define PLAYER_RUN_LEFT "./asset/xmp/player/run_left1.xpm,"\
						"./asset/xmp/player/run_left2.xpm,"\
						"./asset/xmp/player/run_left3.xpm,"\
						"./asset/xmp/player/run_left4.xpm,"\
						"./asset/xmp/player/run_left5.xpm,"\
						"./asset/xmp/player/run_left6.xpm"

#define PLAYER_RUN_TOP "./asset/xmp/player/run_top1.xpm,"\
                        "./asset/xmp/player/run_top2.xpm,"\
                        "./asset/xmp/player/run_top3.xpm,"\
                        "./asset/xmp/player/run_top4.xpm,"\
                        "./asset/xmp/player/run_top5.xpm,"\
                        "./asset/xmp/player/run_top6.xpm"

#define PLAYER_RUN_BOTTOM "./asset/xmp/player/run_bottom1.xpm,"\
                          "./asset/xmp/player/run_bottom2.xpm,"\
                          "./asset/xmp/player/run_bottom3.xpm,"\
                          "./asset/xmp/player/run_bottom4.xpm,"\
                          "./asset/xmp/player/run_bottom5.xpm,"\
                          "./asset/xmp/player/run_bottom6.xpm"

#define PLAYER_IDLE_RIGHT "./asset/xmp/player/idle_right1.xpm,"\
                         "./asset/xmp/player/idle_right2.xpm,"\
                         "./asset/xmp/player/idle_right3.xpm,"\
                         "./asset/xmp/player/idle_right4.xpm"

#define PLAYER_IDLE_LEFT "./asset/xmp/player/idle_left1.xpm,"\
                        "./asset/xmp/player/idle_left2.xpm,"\
                        "./asset/xmp/player/idle_left3.xpm,"\
                        "./asset/xmp/player/idle_left4.xpm"

#define PLAYER_IDLE_TOP "./asset/xmp/player/idle_top1.xpm,"\
                        "./asset/xmp/player/idle_top2.xpm,"\
                        "./asset/xmp/player/idle_top3.xpm,"\
                        "./asset/xmp/player/idle_top4.xpm"

#define PLAYER_IDLE_BOTTOM "./asset/xmp/player/idle_bottom1.xpm,"\
                            "./asset/xmp/player/idle_bottom2.xpm,"\
                            "./asset/xmp/player/idle_bottom3.xpm,"\
                            "./asset/xmp/player/idle_bottom4.xpm"


t_mlx_image ***load_all_frame(void *mlx_ptr) {
    t_mlx_image ***frames;

    frames = malloc(sizeof(t_mlx_image *) * 25);
    frames[0] = load_sprite(mlx_ptr, PLAYER_RUN_TOP, 6);
    frames[1] = load_sprite(mlx_ptr, PLAYER_RUN_BOTTOM, 6);
    frames[2] = load_sprite(mlx_ptr, PLAYER_RUN_LEFT , 6);
    frames[3] = load_sprite(mlx_ptr, PLAYER_RUN_RIGHT, 6);

    frames[4] = load_sprite(mlx_ptr, PLAYER_IDLE_TOP, 4);
    frames[5] = load_sprite(mlx_ptr, PLAYER_IDLE_BOTTOM, 4);
    frames[6] = load_sprite(mlx_ptr, PLAYER_IDLE_LEFT, 4);
    frames[7] = load_sprite(mlx_ptr, PLAYER_IDLE_RIGHT, 4);
    return (frames);
}

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
    t_entity **table;
} t_maps;

typedef struct state {
    void *mlx_ptr;
    void *win_ptr;
    t_mlx_image *buffer;
    t_entity *main_caracter;
    t_mlx_image ***frame;
    t_maps *worlds;
} t_state;

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

void render_maps(const t_state *global) {
    t_mlx_image wall;
    wall.img = mlx_xpm_file_to_image(global->mlx_ptr , "./asset/xmp/wall.xpm" , &wall.width , &wall.heigth);
    wall.addr = mlx_get_data_addr(wall.img , &wall.bits_per_pixel , &wall.line_length , &wall.endian);

    int i = 0;
    int j = 0;

    while (i < global->worlds->h) {
        j = 0;
        while (j < global->worlds->w) {
            if(global->worlds->table[i][j].type == 1)
                put_img_to_img(*global->buffer , wall , j * 32 , i * 32);
            j++;
        }
        i++;
    }
}

int render_next_frame(void *global) {
    t_state *g;
    static uint64_t updated_at = 0;
    g = global;
    if (timestamp_in_ms() - updated_at < (uint64_t) (1000 / 60))
        return (0);
    updated_at = timestamp_in_ms();
    fill_pixel_img(*g->buffer, 0xCACC95);
    render_maps(global);
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

int on_key_up(int keycode, void *global) {
    t_state *g;

    g = global;
    g->main_caracter->idle = 1;
    return (0);
}

int check_collision(t_state * global ,  int x , int y) {
    // Calculate the top-left corner of the player in grid coordinates
    int x1 = x / 32;
    int y1 = y / 32;
    // Calculate the bottom-right corner of the player in grid coordinates
    int x2 = (x + 31) / 32;
    int y2 = (y + 31) / 32;

    // Check all four corners of the player's bounding box
    if (global->worlds->table[y1][x1].type == 1 ||
        global->worlds->table[y1][x2].type == 1 ||
        global->worlds->table[y2][x1].type == 1 ||
        global->worlds->table[y2][x2].type == 1) {
        return 0; // Collision detected
        }

    return 1; // No collision
}

int on_key_down(int keycode, void *global) {
    t_state *g;
    int factor;

    g = global;
    factor = 4;
    g->main_caracter->idle = 0;

    int x = g->main_caracter->x;
    int y = g->main_caracter->y;

    if (keycode == 119) {
        g->main_caracter->direction = 1;
        y = g->main_caracter->y - factor;
    } else if (keycode == 115) {
        g->main_caracter->direction = 2;
        y = g->main_caracter->y + factor;
    } else if (keycode == 97) {
        g->main_caracter->direction = 3;
        x = g->main_caracter->x - factor;
    } else if (keycode == 100) {
        g->main_caracter->direction = 4;
        x = g->main_caracter->x + factor;
    }

    if(check_collision(global , x , y)) {
        g->main_caracter->x = x;
        g->main_caracter->y = y;
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
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    worlds.table = malloc(sizeof(t_entity *) * 16);

    int i = 0;
    int j = 0;

    // initialise _i to entity table
    while(i < 16) {
        worlds.table[i] = malloc(sizeof(t_entity) * 32);
        j = 0;
        while (j < 32) {
            worlds.table[i][j].type = _i[i][j];
            worlds.table[i][j].x = j;
            worlds.table[i][j].y = i;
            j++;
        }
        i++;
    }

    int scale = 32;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, worlds.w * scale, worlds.h * scale, "- _ -");
    buffer.width = worlds.w * scale;
    buffer.heigth = worlds.h * scale;
    buffer.img = mlx_new_image(mlx_ptr, worlds.w * scale, worlds.h * scale);
    buffer.addr = mlx_get_data_addr(buffer.img, &buffer.bits_per_pixel,
                                    &buffer.line_length, &buffer.endian);
    global.win_ptr = win_ptr;
    global.mlx_ptr = mlx_ptr;
    global.buffer = &buffer;
    global.frame = load_all_frame(mlx_ptr);
    global.worlds = &worlds;

    t_entity player;
    player.x = 32;
    player.y = 32;
    player.direction = 1;
    player.idle = 1;


    player.animation = malloc(sizeof(t_animation) * 10);
    player.animation[0] = init_animation(global.frame[0] , 8 , 6);
    player.animation[1] = init_animation(global.frame[1] , 8 , 6);
    player.animation[2] = init_animation(global.frame[2] , 8 , 6);
    player.animation[3] = init_animation(global.frame[3] , 8 , 6);
    player.animation[4] = init_animation(global.frame[4] , 10 , 4);
    player.animation[5] = init_animation(global.frame[5] , 10 , 4);
    player.animation[6] = init_animation(global.frame[6] , 10 , 4);
    player.animation[7] = init_animation(global.frame[7] , 10 , 4);

    global.main_caracter = &player;

    mlx_hook(win_ptr, 03, 1L << 1, on_key_up, &global);
    mlx_hook(win_ptr, 02, 1L << 0, on_key_down, &global);
    mlx_loop_hook(mlx_ptr, render_next_frame, &global);
    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}
