/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:03:26 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/16 09:12:38 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engime.h"

int	on_key_up(int keycode, void *global)
{
    t_state	*g;

    g = global;
    g->main_caracter->idle = 1;
    return (0);
}

int	on_key_down(int keycode, void *global)
{
    t_state	*g;
    int		factor;
    int		x;
    int		y;

    g = global;
    factor = 8;
    g->main_caracter->idle = 0;
    x = g->main_caracter->x;
    y = g->main_caracter->y;
    if (keycode == 119 || keycode == 122)
    {
        g->main_caracter->direction = 1;
        y = g->main_caracter->y - factor;
    }
    else if (keycode == 115)
    {
        g->main_caracter->direction = 2;
        y = g->main_caracter->y + factor;
    }
    else if (keycode == 97 || keycode == 113)
    {
        g->main_caracter->direction = 3;
        x = g->main_caracter->x - factor;
    }
    else if (keycode == 100)
    {
        g->main_caracter->direction = 4;
        x = g->main_caracter->x + factor;
    }
    if (check_collision(global, x, y))
    {
        g->main_caracter->x = x;
        g->main_caracter->y = y;
    }
    return (0);
}