/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:20 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 16:23:32 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_memory.h"
#include "init_door.h"
#include <stdio.h>

void	lst_add_back(int y, int x, t_door **door)
{
	t_door	*tmp;
	t_door	*new;

	if (!door)
		return ;
	new = malloc(sizeof(t_door));
	if (!new)
		return ;
	new->x = x;
	new->y = y;
	new->state = CLOSE;
	new->progress = 1.0;
	new->next = NULL;
	if (!*door)
	{
		*door = new;
		return ;
	}
	tmp = *door;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	create_door(char **map, t_door **door)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'D')
				lst_add_back(y, x, door);
			x++;
		}
		y++;
	}
	return (0);
}

void	init_door(t_game *game)
{
	t_door	*door;
	int		state;

	door = NULL;
	state = create_door(game->map.arr, &door);
	if (state == -1)
	{
		free_map(game);
		free(game);
		exit(1);
	}
	game->door = door;
}
