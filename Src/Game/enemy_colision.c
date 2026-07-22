/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_colision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:45:48 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:57:48 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "enemy_colision.h"

t_door	*e_find_door(int x, int y, t_game *game)
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

t_bool	e_check_door(double x, double y, t_game *game)
{
	t_door	*door;
	int		new_x;
	int		new_y;

	new_x = (int)x;
	new_y = (int)y;
	if (game->map.arr[new_y][new_x] != 'D')
		return (FALSE);
	door = e_find_door(x, y, game);
	if (!door)
		return (FALSE);
	if (door->state == OPEN)
		return (FALSE);
	return (TRUE);
}

t_bool	enemy_colision(double x, double y, t_game *game)
{
	if ((int)y < 0 || (int)x < 0)
		return (TRUE);
	if (y >= game->map.height || x >= ft_strlen(game->map.arr[(int)y]))
		return (TRUE);
	if (game->map.arr[(int)y][(int)(x + ENEMY_RADIUS)] == '1')
		return (TRUE);
	if (game->map.arr[(int)y][(int)(x - ENEMY_RADIUS)] == '1')
		return (TRUE);
	if (game->map.arr[(int)(y + ENEMY_RADIUS)][(int)x] == '1')
		return (TRUE);
	if (game->map.arr[(int)(y - ENEMY_RADIUS)][(int)x] == '1')
		return (TRUE);
	return (FALSE);
}

t_bool	e_iscoliding(double x, double y, t_game *game)
{
	if (enemy_colision(x, y, game))
		return (TRUE);
	if (e_check_door(x, y, game))
		return (TRUE);
	return (FALSE);
}
