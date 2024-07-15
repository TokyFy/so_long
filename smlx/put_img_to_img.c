/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:31:24 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/05 10:31:41 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

void	put_img_to_img(t_mlx_image dst, t_mlx_image src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < src.width)
	{
		j = 0;
		while (j < src.heigth)
		{
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}
