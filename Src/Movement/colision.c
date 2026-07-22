/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:07 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:57:23 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"

t_door	*find_door(int x, int y, t_game *game)
{
	t_door	*tmp;

	tmp = game->door;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_bool	check_wall_radius(double x, double y, t_game *game)
{
	if (game->map.arr[(int)y][(int)(x + PLAYER_RADIUS)] == '1')
		return (TRUE);
	if (game->map.arr[(int)y][(int)(x - PLAYER_RADIUS)] == '1')
		return (TRUE);
	if (game->map.arr[(int)(y + PLAYER_RADIUS)][(int)x] == '1')
		return (TRUE);
	if (game->map.arr[(int)(y - PLAYER_RADIUS)][(int)x] == '1')
		return (TRUE);
	return (FALSE);
}

t_bool	check_door(double x, double y, t_game *game)
{
	t_door	*door;
	int		new_x;
	int		new_y;

	new_x = (int)x;
	new_y = (int)y;
	if (game->map.arr[new_y][new_x] != 'D')
		return (FALSE);
	door = find_door(x, y, game);
	if (!door)
		return (FALSE);
	if (door->state == OPEN)
		return (FALSE);
	return (TRUE);
}

t_bool	iscoliding(double x, double y, t_game *game)
{
	if (check_wall_radius(x, y, game))
		return (TRUE);
	if (check_door(x, y, game))
		return (TRUE);
	return (FALSE);
}
