/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:55:14 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/15 11:30:24 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"
#include <stdio.h>
#include <stdlib.h>

t_mlx_image	**load_sprite(void *mlx_ptr, const char *xpm, int length)
{
	t_mlx_image	**frames;
	t_mlx_image	*image;
	char		**xpms;
	int			i;

	xpms = ft_split(xpm, ',');
	i = 0;
	frames = malloc(sizeof(t_mlx_image) * length);
	while (i < length)
	{
		image = malloc(sizeof(t_mlx_image));
		image->img = mlx_xpm_file_to_image(mlx_ptr, xpms[i], &image->width,
				&image->heigth);
		image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
				&image->line_length, &image->endian);
		frames[i] = image;
		printf("%s [Loaded]\n", xpms[i]);
		i++;
	}
	ft_free_split(xpms);
	return (frames);
}

t_animation	*init_animation(t_mlx_image **frame, int delay, int length)
{
	t_animation	*animation;

	animation = malloc(sizeof(t_animation));
	animation->frames = frame;
	animation->delay = delay;
	animation->length = length;
	animation->current = 0;
	animation->cdelay = 0;
	return (animation);
}
