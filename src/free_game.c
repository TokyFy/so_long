/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:23:05 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/26 11:04:49 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../engime/engime.h"
#include "../so_long.h"

void	destroy_animation(t_animation *animation)
{
	free(animation);
}

void	destroy_entity(t_entity *entity)
{
	int	i;

	if (entity == NULL)
		return ;
	i = 0;
	while (i < entity->c_animation)
	{
		destroy_animation(entity->animation[i]);
		i++;
	}
	free(entity->animation);
	free(entity);
}

void	destroy_worlds(t_maps *worlds)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!worlds || !worlds->table)
		return ;
	while (i < worlds->h)
	{
		j = 0;
		while (j < worlds->w)
		{
			destroy_entity(worlds->table[i][j]);
			j++;
		}
		free(worlds->table[i]);
		i++;
	}
	free(worlds->table);
	free(worlds);
}

void	free_global(t_state *global)
{
	destroy_entity(global->main_caracter);
	destroy_worlds(global->worlds);
	free_all_frame(global);
	if (global->buffer)
		destroy_image(global, global->buffer);
	if (global->mlx_ptr && global->win_ptr)
	{
		mlx_destroy_window(global->mlx_ptr, global->win_ptr);
	}
	mlx_destroy_display(global->mlx_ptr);
	free(global->mlx_ptr);
}

int	exit_game(t_state *global, int error)
{
	if (global)
		free_global(global);
	exit(error);
}
