/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:15:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/19 15:18:02 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engime/engime.h"
#include "smlx/smlx.h"
#include "so_long.h"
#include <stdlib.h>

void init_player(t_state *global) {
    t_entity *player = malloc(sizeof(t_entity));

    player->x = 32;
    player->y = 32;
    player->direction = 1;
    player->idle = 1;
    player->animation = malloc(sizeof(t_animation) * 10);
    player->animation[0] = init_animation(global->frame[0], 8, 6);
    player->animation[1] = init_animation(global->frame[1], 8, 6);
    player->animation[2] = init_animation(global->frame[2], 8, 6);
    player->animation[3] = init_animation(global->frame[3], 8, 6);
    player->animation[4] = init_animation(global->frame[4], 10, 4);
    player->animation[5] = init_animation(global->frame[5], 10, 4);
    player->animation[6] = init_animation(global->frame[6], 10, 4);
    player->animation[7] = init_animation(global->frame[7], 10, 4);
    player->c_animation = 8;
    global->main_caracter = player;
}

void init_global(t_state *global) {
    void *mlx_ptr;
    mlx_ptr = mlx_init();
    global->buffer = NULL;
    global->mlx_ptr = NULL;
    global->win_ptr = NULL;
    global->main_caracter = NULL;
    global->frame = NULL;
    global->worlds = NULL;
    global->winning = 0;
    global->mlx_ptr = mlx_ptr;
    global->frame = load_all_frame(mlx_ptr);
}

void init_windows(t_state *global) {
    void *win_ptr;
    t_mlx_image *buffer = malloc(sizeof(t_mlx_image));

    win_ptr = mlx_new_window(global->mlx_ptr, global->worlds->w * SCALE, global->worlds->h
                                                                         * SCALE, "- _ -");
    global->win_ptr = win_ptr;

    buffer->width = global->worlds->w * SCALE;
    buffer->heigth = global->worlds->h * SCALE;
    buffer->img = mlx_new_image(global->mlx_ptr, global->worlds->w * SCALE,
                                global->worlds->h * SCALE);
    buffer->addr = mlx_get_data_addr(buffer->img, &(buffer->bits_per_pixel),
                                     &(buffer->line_length), &(buffer->endian));
    global->buffer = buffer;
}


void destroy_animation(t_animation *animation) {
    free(animation);
}

void destroy_entity(t_entity *entity) {
    if (entity == NULL)
        return;

    int i = 0;

    while (i < entity->c_animation) {
        destroy_animation(entity->animation[i]);
        i++;
    }
    free(entity->animation);
    free(entity);
}

void destroy_worlds(t_maps *worlds) {
    int i = 0;
    int j = 0;

    while (i < worlds->h) {
        j = 0;
        while (j < worlds->w) {
            destroy_entity(worlds->table[i][j]);
            j++;
        }
        free(worlds->table[i]);
        i++;
    }
    free(worlds->table);
    free(worlds);
}

void free_global(t_state *global) {
    destroy_entity(global->main_caracter);
    destroy_worlds(global->worlds);
    free_all_frame(global);
    destroy_image(global, global->buffer);
    mlx_destroy_window(global->mlx_ptr, global->win_ptr);
    mlx_destroy_display(global->mlx_ptr);
    free(global->mlx_ptr);
}

int exit_game(t_state *global) {
    free_global(global);
    exit(1);
}

int main(int argc, char *argv[]) {
    t_state global;

    if (argc != 2) {
        write(2, "Map file required", 17);
        return (1);
    }

    srand(time(NULL));
    init_global(&global);
    init_player(&global);
    init_maps(&global, argv[1]);
    init_windows(&global);

    mlx_hook(global.win_ptr, 03, 1L << 1, on_key_up, &global);
    mlx_hook(global.win_ptr, 02, 1L << 0, on_key_down, &global);
    mlx_hook(global.win_ptr, 17, 0, exit_game, &global);
    mlx_loop_hook(global.mlx_ptr, render_next_frame, &global);
    mlx_loop(global.mlx_ptr);
}
