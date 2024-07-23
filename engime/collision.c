/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:03:01 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/19 14:33:45 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "engime.h"
#include <stdio.h>

int	check_collision_arrount(t_state *global, int x, int y, int type)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = (x + 12) / 32;
	y1 = (y) / 32;
	x2 = (x + 31 - 12) / 32;
	y2 = (y + 31) / 32;
	return (global->worlds->table[y1][x1]->type == type
		|| global->worlds->table[y1][x2]->type == type
		|| global->worlds->table[y2][x1]->type == type
		|| global->worlds->table[y2][x2]->type == type);
}

void	collision_modifier(t_state *global, int x, int y, void (*mod)(t_state *,
			t_entity *))
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	x1 = (x + 12) / 32;
	y1 = (y) / 32;
	x2 = (x + 31 - 12) / 32;
	y2 = (y + 31) / 32;
	if (mod == NULL)
		return ;
	mod(global, global->worlds->table[y1][x1]);
	mod(global, global->worlds->table[y1][x2]);
	mod(global, global->worlds->table[y2][x1]);
	mod(global, global->worlds->table[y2][x1]);
}

void	collect_collision(t_state *global, t_entity *entity)
{
	if (entity->type != 2)
		return ;
	entity->type = -1;
	global->worlds->collect--;
}

void	winning_collision(t_state *global, t_entity *entity)
{
	if (entity->type != 3 || global->worlds->collect > 0)
		return ;
	global->winning = 1;
}

int	check_collision(t_state *global, int x, int y)
{
	if (check_collision_arrount(global, x, y, 1))
		return (1);
	if (check_collision_arrount(global, x, y, 2))
	{
		collision_modifier(global, x, y, collect_collision);
		return (0);
	}
	if (check_collision_arrount(global, x, y, 3))
	{
		collision_modifier(global, x, y, winning_collision);
		return (0);
	}
	return (0);
}
