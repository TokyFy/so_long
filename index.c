/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:15:29 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/23 15:27:06 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engime/engime.h"
#include "so_long.h"

int	valid_ber_filename(char *path)
{
	int		len;
	char	*ext;

	len = ft_strlen(path);
	if (len < 4)
		return (0);
	ext = path + (len - 4);
	if (*(ext - 1) == '/')
		return (0);
	if (ext != ft_strnstr(path, ".ber", len))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_state	global;

	if (argc != 2 || !valid_ber_filename(argv[1]))
	{
		write(2, "Map file required", 17);
		return (1);
	}
	srand(time(NULL));
	init_global(&global);
	init_player(&global);
	init_maps(&global, argv[1]);
	init_windows(&global);
	mlx_hook(global.win_ptr, 03, 1L << 1, on_key_up, &global);
	mlx_hook(global.win_ptr, 02, 1L << 0, on_key_down, &global);
	mlx_hook(global.win_ptr, 17, 0, exit_game, &global);
	mlx_loop_hook(global.mlx_ptr, render_next_frame, &global);
	mlx_loop(global.mlx_ptr);
}
