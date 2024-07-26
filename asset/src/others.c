/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:43:24 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/26 10:43:32 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*get_obstacle_11(void)
{
	const char	*obstacle_11;

	obstacle_11 = "asset/xmp/obst/obs11.xpm";
	return (obstacle_11);
}

const char	*get_temporary_obstacle(void)
{
	const char	*temporary_obstacle;

	temporary_obstacle = "./asset/xmp/wall.xpm";
	return (temporary_obstacle);
}

const char	*get_exit(void)
{
	const char	*exit;

	exit = "./asset/xmp/exit.xpm";
	return (exit);
}
