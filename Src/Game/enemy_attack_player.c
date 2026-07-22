/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:45:41 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:56:34 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "delta_time.h"
#include "enemy_attack_player.h"
#include "stdio.h"
#include <sys/time.h>

void	attack_player(t_game *game, t_entity *enemy)
{
	double	curent_time;

	curent_time = get_time();
	if (curent_time - enemy->spec.e_data.last_attack >= 4000)
	{
		enemy->spec.e_data.last_attack = curent_time;
		game->player.hp -= 20;
	}
	(void)game;
}
