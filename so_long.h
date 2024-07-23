/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:52:00 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/23 15:26:58 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "smlx/smlx.h"
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define SCALE 32

typedef struct entity
{
	int			type;
	int			x;
	int			y;
	int			idle;
	int			direction;
	t_animation	**animation;
	int			c_animation;
}				t_entity;

typedef struct maps
{
	int			w;
	int			h;
	t_entity	***table;
	int			collect;
}				t_maps;

typedef struct state
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mlx_image	*buffer;
	t_entity	*main_caracter;
	t_mlx_image	***frame;
	t_maps		*worlds;
	int			winning;
}				t_state;

int				**ber_file_parser(char *path, int *w, int *h);
int				exit_game(t_state *global);

void			init_player(t_state *global);
void			init_global(t_state *global);
void			init_windows(t_state *global);
void			destroy_animation(t_animation *animation);
void			destroy_entity(t_entity *entity);
void			destroy_worlds(t_maps *worlds);
void			free_global(t_state *global);
int				exit_game(t_state *global);

#endif // !SO_LONG_H
