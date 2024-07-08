/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:15:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/08 10:24:01 by franaivo         ###   ########.fr       */
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

t_mlx_image ***load_all_frame(void *mlx_ptr) {
    t_mlx_image ***frames;

    frames = malloc(sizeof(t_mlx_image **) * 25);
    frames[0] = load_sprite(mlx_ptr, PLAYER_RUN_RIGHT, 6);
    frames[1] = load_sprite(mlx_ptr, PLAYER_RUN_LEFT, 6);
    frames[2] = load_sprite(mlx_ptr, PLAYER_RUN_TOP, 6);
    frames[3] = load_sprite(mlx_ptr, PLAYER_RUN_BOTTOM, 6);
    return (frames);
}

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
    t_mlx_image ***frame;
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
    global.frame = load_all_frame(mlx_ptr);

    t_entity player;
    player.x = 0;
    player.y = 0;
    player.direction = 1;
    player.idle = 0;


    player.animation = malloc(sizeof(t_animation) * 10);
    player.animation[0] = init_animation(global.frame[0] , 20 , 6);
    player.animation[0] = init_animation(global.frame[1] , 20 , 6);
    player.animation[0] = init_animation(global.frame[2] , 20 , 6);
    player.animation[0] = init_animation(global.frame[3] , 20 , 6);

    global.main_caracter = &player;


    mlx_hook(win_ptr, 03, 1L << 1, on_key_up, &global);
    mlx_hook(win_ptr, 02, 1L << 0, on_key_down, &global);
    mlx_loop_hook(mlx_ptr, render_next_frame, &global);
    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}
