/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:37:15 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/05 11:55:14 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "smlx.h"



t_mlx_image **load_sprite(void *mlx_ptr, char *xpm, int length) {
    t_mlx_image **frames;
    t_mlx_image *image;
    char **xpms = ft_split(xpm, ',');
    int i = 0;
    frames = malloc(sizeof(t_mlx_image) * length);
    while (i < length) {
        image = malloc(sizeof(t_mlx_image));
        image->img = mlx_xpm_file_to_image(mlx_ptr, xpms[i], &image->width, &image->heigth);
        image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
        frames[i] = image;
    }
    
    ft_free_split(xpms);
    return (frames);
}
