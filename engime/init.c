/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:31:58 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/24 14:32:14 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engime.h"

void	init_static_wall(t_state *global, t_entity *entity)
{
	t_animation	**anim;

	if (entity->type != 1)
		return ;
	anim = malloc(sizeof(t_animation *));
	if (entity->x == 0 && entity->y == 0)
		anim[0] = init_animation(global->frame[12], 60, 1);
	else if (entity->y == 0 && entity->x + 1 == global->worlds->w)
		anim[0] = init_animation(global->frame[13], 60, 1);
	else if (entity->x == 0 && entity->y + 1 == global->worlds->h)
		anim[0] = init_animation(global->frame[14], 60, 1);
	else if (entity->x + 1 == global->worlds->w && entity->y
		+ 1 == global->worlds->h)
		anim[0] = init_animation(global->frame[15], 60, 1);
	else if (entity->y == 0)
		anim[0] = init_animation(global->frame[8], 60, 1);
	else if (entity->y + 1 == global->worlds->h)
		anim[0] = init_animation(global->frame[9], 60, 1);
	else if (entity->x == 0)
		anim[0] = init_animation(global->frame[10], 60, 1);
	else if (entity->x + 1 == global->worlds->w)
		anim[0] = init_animation(global->frame[11], 60, 1);
	else
		anim[0] = init_animation(global->frame[17 + ft_random(0, 7)], 60, 1);
	entity->animation = anim;
}

void	init_static_collect(t_state *global, t_entity *entity)
{
	t_animation	**animations;

	if (entity->type != 2)
		return ;
	animations = malloc(sizeof(t_animation *));
	animations[0] = init_animation(global->frame[27 + ft_random(0, 3)],
			ft_random(8, 12), 4);
	entity->animation = animations;
}

void	init_static_exit(t_state *global, t_entity *entity)
{
	t_animation	**animations;

	if (entity->type != 3)
		return ;
	animations = malloc(sizeof(t_animation *));
	animations[0] = init_animation(global->frame[31], 60, 1);
	entity->animation = animations;
}

void	init_static_ground(t_state *global, t_entity *entity)
{
	t_animation	**animations;

	if (entity->type > 0 && entity->type < 4)
		return ;
	animations = malloc(sizeof(t_animation *));
	animations[0] = init_animation(global->frame[26 - (ft_random(1, 9) == 5)],
			60, 1);
	entity->animation = animations;
}

void	init_static_entity(t_state *global, t_entity *entity)
{
	init_static_wall(global, entity);
	init_static_collect(global, entity);
	init_static_exit(global, entity);
	init_static_ground(global, entity);
	entity->direction = 0;
	entity->idle = 1;
	entity->c_animation = 1;
}
