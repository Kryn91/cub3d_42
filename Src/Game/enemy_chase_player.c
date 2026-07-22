/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_chase_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:45:44 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:57:48 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy_chase_player.h"
#include "enemy_colision.h"
#include "entity.h"
#include "math.h"
#include "vector_manipulation.h"

void	chase_player(t_game *game, t_entity *enemy)
{
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;
	double	movespeed;

	dx = game->player.pos_x - enemy->pos_x;
	dy = game->player.pos_y - enemy->pos_y;
	normalize_vector(&dx, &dy);
	enemy->dir_x = dx;
	enemy->dir_y = dy;
	movespeed = 0.08;
	new_x = enemy->pos_x + enemy->dir_x * movespeed;
	new_y = enemy->pos_y + enemy->dir_y * movespeed;
	if (e_iscoliding(new_x, enemy->pos_y, game) == FALSE)
		enemy->pos_x = new_x;
	if (e_iscoliding(enemy->pos_x, new_y, game) == FALSE)
		enemy->pos_y = new_y;
}
