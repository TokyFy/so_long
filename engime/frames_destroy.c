/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:41:57 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/26 10:42:00 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engime.h"

void	free_frame(t_state *global, t_mlx_image **frame, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		destroy_image(global, frame[i]);
		i++;
	}
	free(frame);
}

void	free_frame_set(t_state *global, int start, int slen, int flen)
{
	int	i;

	i = 0;
	while (i < slen)
	{
		free_frame(global, global->frame[i + start], flen);
		i++;
	}
}

void	free_all_frame(t_state *global)
{
	free_frame_set(global, 0, 4, 6);
	free_frame_set(global, 4, 4, 4);
	free_frame_set(global, 8, 19, 1);
	free_frame_set(global, 27, 4, 4);
	free_frame_set(global, 31, 1, 1);
	free(global->frame);
}
