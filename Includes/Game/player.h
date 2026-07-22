/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:29:36 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:51:13 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "boolean.h"

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	mouse_x;
	double	mouse_y;
	double	rotation_angle;
	double	hp;
	t_bool	is_dead;
}			t_player;

typedef struct s_input
{
	t_bool	a;
	t_bool	d;
	t_bool	w;
	t_bool	s;
	t_bool	e;
}			t_input;

#endif
