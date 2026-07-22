/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:29:11 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:29:12 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# define ENEMY_PATH "chemin/a mettre"
# define ENEMY_RADIUS 0.25
# include "render.h"

typedef struct s_projectile_data
{
	double	dir_x;
	double	dir_y;
}	t_projectile_data;

typedef struct s_enemy_data
{
	double	hp;
	double	hit_radius;
	double	last_attack;
}	t_enemy_data;

typedef union u_entity_spec
{
	t_enemy_data		e_data;
	t_projectile_data	p_data;
}	t_entity_spec;

typedef enum e_entity_type
{
	ENEMY,
	PROJECTILE
}	t_entity_type;

typedef enum e_enemy_state
{
	PATROL,
	CHASE
}	t_enemy_state;

typedef struct s_entity
{
	t_entity_type	type;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			transform_x;
	double			transform_y;
	double			last_frame_time;
	int				frame;
	int				state;
	t_enemy_state	estate;
	t_texture		tex[3];
	t_entity_spec	spec;
}	t_entity;

#endif
