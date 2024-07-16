/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:29:21 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/15 10:33:13 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

void	put_pixel_img(t_mlx_image img, unsigned int x, unsigned int y,
		int color)
{
	char	*dst;

	if (color == 0xFF000000)
		return ;
	if (x > img.width || y > img.heigth)
		return ;
	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
