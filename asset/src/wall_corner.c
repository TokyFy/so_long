/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_corner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:43:30 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/26 10:43:32 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*get_wall_top_left(void)
{
	const char	*wall_top_left;

	wall_top_left = "./asset/xmp/wall/wall_top_left.xpm";
	return (wall_top_left);
}

const char	*get_wall_bottom_left(void)
{
	const char	*wall_bottom_left;

	wall_bottom_left = "./asset/xmp/wall/wall_bottom_left.xpm";
	return (wall_bottom_left);
}

const char	*get_wall_top_right(void)
{
	const char	*wall_top_right;

	wall_top_right = "./asset/xmp/wall/wall_top_right.xpm";
	return (wall_top_right);
}

const char	*get_wall_bottom_right(void)
{
	const char	*wall_bottom_right;

	wall_bottom_right = "./asset/xmp/wall/wall_bottom_right.xpm";
	return (wall_bottom_right);
}
