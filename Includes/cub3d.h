/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:45:01 by apeterso          #+#    #+#             */
/*   Updated: 2026/08/19 17:52:51 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "boolean.h"
# include "door.h"
# include "entity.h"
# include "hand.h"
# include "libft.h"
# include "map.h"
# include "player.h"
# include "render.h"
# include "spell.h"

typedef struct s_fps
{
	double		last_frame;
	double		cap;
}				t_fps;

typedef struct s_time
{
	double		last_time;
	double		delta_time;
}				t_time;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_door		*door;
	t_map		map;
	t_input		input;
	t_list		*entity_lst;
	t_time		delta_time;
	t_fps		fps;
	double		time;
	double		old_time;
	double		wall_dist_buf[SCREEN_WIDTH];
	t_texture	door_texture;
	t_texture	game_over_tex;
	t_hand		hand;
	t_spell		spell;
	int			first_loop;
	double		last_shoot_time;
}				t_game;

void			parsing(int ac, char **av, t_game *game);

#endif
