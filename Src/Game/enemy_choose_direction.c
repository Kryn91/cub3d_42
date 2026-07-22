/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_choose_direction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:45:46 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 16:10:29 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy_choose_direction.h"
#include "enemy_colision.h"
#include "vector_manipulation.h"
#include <stdlib.h>

void	dirs_init(t_vec dirs[8])
{
	dirs[0].x = 1;
	dirs[0].y = 0;
	dirs[1].x = -1;
	dirs[1].y = 0;
	dirs[2].x = 0;
	dirs[2].y = 1;
	dirs[3].x = 0;
	dirs[3].y = -1;
	dirs[4].x = 1;
	dirs[4].y = 1;
	dirs[5].x = -1;
	dirs[5].y = 1;
	dirs[6].x = 1;
	dirs[6].y = -1;
	dirs[7].x = -1;
	dirs[7].y = -1;
}

void	choose_direction(t_entity *enemy, t_game *game)
{
	int		i;
	t_vec	dirs[8];

	dirs_init(dirs);
	i = rand() % 8;
	while (i < 8)
	{
		if (!e_iscoliding(enemy->pos_x + dirs[i].x, enemy->pos_y + dirs[i].y,
				game))
		{
			enemy->dir_x = dirs[i].x;
			enemy->dir_y = dirs[i].y;
			return ;
		}
		i++;
	}
}
