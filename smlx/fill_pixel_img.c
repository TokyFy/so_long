/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:36:17 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/05 10:36:30 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

void fill_pixel_img(t_mlx_image img, int color) {
    int y;
    int x;

    y = 0;
    x = 0;
    while (y < img.heigth) {
        x = 0;
        while (x < img.width) {
            put_pixel_img(img, x, y, color);
            x++;
        }
        y++;
    }
}


