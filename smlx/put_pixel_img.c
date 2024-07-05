/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:28:15 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/05 10:29:21 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

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
