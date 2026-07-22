/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:35:42 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:58:04 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLISION_H
# define COLISION_H

# include "cub3d.h"
# define PLAYER_RADIUS 0.15

typedef enum e_collision
{
	COL_NONE,
	COL_WALL,
	COL_ENEMY
}		t_col;

t_bool	iscoliding(double x, double y, t_game *game);
t_door	*find_door(int x, int y, t_game *game);
t_bool	check_wall_radius(double x, double y, t_game *game);

#endif
