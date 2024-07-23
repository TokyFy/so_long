/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:03:26 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/23 15:35:53 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engime.h"

int	on_key_up(int keycode, void *global)
{
	t_state	*g;

	(void)(keycode);
	g = global;
	g->main_caracter->idle = 1;
	return (0);
}

void	move_player(int keycode, t_entity *player, int *x, int *y)
{
	int	factor;

	*x = player->x;
	*y = player->y;
	factor = 8;
	if (keycode == 119 || keycode == 122)
	{
		player->direction = 1;
		*y = player->y - factor;
	}
	else if (keycode == 115)
	{
		player->direction = 2;
		*y = player->y + factor;
	}
	else if (keycode == 97 || keycode == 113)
	{
		player->direction = 3;
		*x = player->x - factor;
	}
	else if (keycode == 100)
	{
		player->direction = 4;
		*x = player->x + factor;
	}
}

int	on_key_down(int keycode, void *global)
{
	t_state	*g;
	int		x;
	int		y;

	g = global;
	g->main_caracter->idle = 0;
	move_player(keycode, g->main_caracter, &x, &y);
	if (!check_collision(global, x, y))
	{
		g->main_caracter->x = x;
		g->main_caracter->y = y;
	}
	return (0);
}
