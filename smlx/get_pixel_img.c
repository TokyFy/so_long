/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:29:50 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/15 10:41:40 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "smlx.h"

unsigned int	get_pixel_img(t_mlx_image img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_length) + (x
				* img.bits_per_pixel / 8))));
}
