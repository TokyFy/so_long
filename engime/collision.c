/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:03:01 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/16 15:42:12 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "engime.h"
#include <stdio.h>

int collision_modifier(t_state *global , int type , int ret , void (mod)(t_state * , t_entity *))
{
	 if (global->worlds->table[y1][x1]->type == type
        || global->worlds->table[y1][x2]->type == type
        || global->worlds->table[y2][x1]->type == type
        || global->worlds->table[y2][x2]->type == type)
    {
		if(!mode)
			return ret;

		 if (global->worlds->table[y1][x1]->type == 2)
		{
            mod(global , global->worlds->table[y1][x1]);
		}
        if (global->worlds->table[y1][x2]->type == 2)
		{
            mod(global , global->worlds->table[y1][x2]);
		}
        if (global->worlds->table[y2][x1]->type == 2)
		{
			mod(global , global->worlds->table[y1][x2]);
		}
        if (global->worlds->table[y2][x2]->type == 2)
		{
			mod(global , global->worlds->table[y2][x2]);
		}
        return (ret);
    }
}

int	check_collision(t_state *global, int x, int y)
{
    int	x1;
    int	y1;
    int	x2;
    int	y2;

    x1 = (x + 12) / 32;
    y1 = (y) / 32;
    x2 = (x + 31 - 12) / 32;
    y2 = (y + 31) / 32;

    if (collision_modifier(global , 1  , 1 , NULL))
    {
        return (1);
    }

    if (global->worlds->table[y1][x1]->type == 2
        || global->worlds->table[y1][x2]->type == 2
        || global->worlds->table[y2][x1]->type == 2
        || global->worlds->table[y2][x2]->type == 2)
    {
        if (global->worlds->table[y1][x1]->type == 2)
		{
            global->worlds->table[y1][x1]->type = -1;
			global->worlds->collect--;
		}
        if (global->worlds->table[y1][x2]->type == 2)
		{
            global->worlds->table[y1][x2]->type = -1;
			global->worlds->collect--;
		}
        if (global->worlds->table[y2][x1]->type == 2)
		{
			global->worlds->collect--;
            global->worlds->table[y2][x1]->type = -1;
		}
        if (global->worlds->table[y2][x2]->type == 2)
		{
			global->worlds->collect--;
            global->worlds->table[y2][x2]->type = -1;
		}
        return (1);
    }

	 if (global->worlds->table[y1][x1]->type == 3
        || global->worlds->table[y1][x2]->type == 3
        || global->worlds->table[y2][x1]->type == 3
        || global->worlds->table[y2][x2]->type == 3)
    {
        return (1);
    }
    return (1);
}