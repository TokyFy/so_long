/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_idle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:50:39 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/26 10:43:32 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*get_player_idle_right(void)
{
	const char	*player_idle_right;

	player_idle_right = "./asset/xmp/player/idle_right1.xpm,"
		"./asset/xmp/player/idle_right2.xpm,"
		"./asset/xmp/player/idle_right3.xpm,"
		"./asset/xmp/player/idle_right4.xpm";
	return (player_idle_right);
}

const char	*get_player_idle_left(void)
{
	const char	*player_idle_left;

	player_idle_left = "./asset/xmp/player/idle_left1.xpm,"
		"./asset/xmp/player/idle_left2.xpm,"
		"./asset/xmp/player/idle_left3.xpm,"
		"./asset/xmp/player/idle_left4.xpm";
	return (player_idle_left);
}

const char	*get_player_idle_top(void)
{
	const char	*player_idle_top;

	player_idle_top = "./asset/xmp/player/idle_top1.xpm,"
		"./asset/xmp/player/idle_top2.xpm,"
		"./asset/xmp/player/idle_top3.xpm,"
		"./asset/xmp/player/idle_top4.xpm";
	return (player_idle_top);
}

const char	*get_player_idle_bottom(void)
{
	const char	*player_idle_bottom;

	player_idle_bottom = "./asset/xmp/player/idle_bottom1.xpm,"
		"./asset/xmp/player/idle_bottom2.xpm,"
		"./asset/xmp/player/idle_bottom3.xpm,"
		"./asset/xmp/player/idle_bottom4.xpm";
	return (player_idle_bottom);
}
