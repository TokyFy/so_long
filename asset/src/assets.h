/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:30:53 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/24 15:50:01 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

const char	*get_player_run_right(void);
const char	*get_player_run_left(void);
const char	*get_player_run_top(void);
const char	*get_player_run_bottom(void);
const char	*get_player_idle_right(void);

const char	*get_player_idle_right(void);
const char	*get_player_idle_left(void);
const char	*get_player_idle_top(void);
const char	*get_player_idle_bottom(void);

# define PLAYER_RUN_RIGHT get_player_run_right
# define PLAYER_RUN_LEFT get_player_run_left
# define PLAYER_RUN_TOP get_player_run_top
# define PLAYER_RUN_BOTTOM get_player_run_bottom

# define PLAYER_IDLE_RIGHT get_player_idle_right
# define PLAYER_IDLE_LEFT get_player_idle_left
# define PLAYER_IDLE_TOP get_player_idle_top
# define PLAYER_IDLE_BOTTOM get_player_idle_bottom

#endif
