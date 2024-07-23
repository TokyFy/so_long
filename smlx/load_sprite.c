/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:55:14 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/19 15:25:52 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "smlx.h"
#include <stdlib.h>

t_mlx_image	**load_sprite(void *mlx_ptr, const char *xpm, int length)
{
	t_mlx_image	**frames;
	t_mlx_image	*image;
	char		**xpms;
	int			i;

	xpms = ft_split(xpm, ',');
	i = 0;
	frames = ft_calloc(sizeof(t_mlx_image), length);
	while (i < length)
	{
		image = malloc(sizeof(t_mlx_image));
		image->img = mlx_xpm_file_to_image(mlx_ptr, xpms[i], &image->width,
				&image->heigth);
		image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
				&image->line_length, &image->endian);
		frames[i] = image;
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

void	destroy_image(void *global, t_mlx_image *img)
{
	t_state	*g;

	g = global;
	mlx_destroy_image(g->mlx_ptr, img->img);
	free(img);
}
