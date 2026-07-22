/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:45:59 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:57:48 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy_choose_direction.h"
#include "enemy_colision.h"
#include "enemy_patrol.h"
#include "math.h"

void	change_dir(t_entity *enemy, double x, double y)
{
	double	length;

	length = sqrt((x * x) + (y * y));
	if (length == 0)
		return ;
	enemy->dir_x = x / length;
	enemy->dir_y = y / length;
}

void	patrol(t_entity *enemy, t_game *game)
{
	double	movespeed;
	double	new_x;
	double	new_y;

	movespeed = 0.04;
	new_x = enemy->pos_x + enemy->dir_x * movespeed;
	new_y = enemy->pos_y + enemy->dir_y * movespeed;
	enemy->pos_x = new_x;
	if (!e_iscoliding(enemy->pos_x, new_y, game))
		enemy->pos_y = new_y;
	if (e_iscoliding(new_x, new_y, game))
		choose_direction(enemy, game);
}
