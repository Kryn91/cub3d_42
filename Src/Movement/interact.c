/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:13 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:53:48 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"
#include "interact.h"
#include <stdio.h>

void	interact(t_game *game)
{
	int		x;
	int		y;
	t_door	*door;

	x = (int)(game->player.pos_x + game->player.dir_x);
	y = (int)(game->player.pos_y + game->player.dir_y);
	if (!game->input.e)
		return ;
	if (game->map.arr[y][x] != 'D')
		return ;
	door = find_door(x, y, game);
	if (!door)
		return ;
	if (door->state == CLOSE)
	{
		door->state = PROGRESS;
	}
	if (door->state == OPEN)
	{
		door->state = CLOSING;
	}
}
