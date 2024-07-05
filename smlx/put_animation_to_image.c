/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_animation_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:32:58 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/05 10:33:42 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

void put_animation_to_image(t_mlx_image img, t_animation *animation, uint x,
                            uint y) {
    put_img_to_img(img, *(animation->frames[animation->current]), x, y);
    animation->cdelay--;
    if (animation->cdelay <= 0) {
        animation->current++;
        animation->cdelay = animation->delay;
    }
    if (animation->current > animation->length - 1)
        animation->current = 0;
}

