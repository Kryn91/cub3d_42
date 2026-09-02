/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:20 by apeterso          #+#    #+#             */
/*   Updated: 2026/09/02 13:15:46 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_game.h"
#include "free_memory.h"
#include "init_door.h"
#include <stdio.h>

int	lst_add_back(int y, int x, t_door **door)
{
	t_door		*tmp;
	t_door		*new;

	new = malloc(sizeof(t_door));
	if (!new)
		return (1);
	new->x = x;
	new->y = y;
	new->state = CLOSE;
	new->progress = 1.0;
	new->next = NULL;
	if (!*door)
	{
		*door = new;
		return (0);
	}
	tmp = *door;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
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
			{
				if (lst_add_back(y, x, door) == 1)
					return (1);
			}
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
	game->door = door;
	if (state == 1)
	{
		ft_putstr_fd("Error\nAllocating memory malloc fail\n", 2);
		free_game(game);
		exit(1);
	}
}
