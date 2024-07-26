/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:03:26 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/26 11:08:51 by franaivo         ###   ########.fr       */
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

void	print_move(int move)
{
	ft_putstr_fd("Move : ", 1);
	ft_putnbr_fd(move, 1);
	ft_putstr_fd(" \n", 1);
}

int	on_key_down(int keycode, void *global)
{
	t_state		*g;
	int			x;
	int			y;
	static int	move = 0;

	g = global;
	if (keycode == 65307)
		exit_game(global, 0);
	g->main_caracter->idle = 0;
	move_player(keycode, g->main_caracter, &x, &y);
	if (!check_collision(global, x, y))
	{
		move++;
		g->main_caracter->x = x;
		g->main_caracter->y = y;
		print_move(move);
	}
	return (0);
}
