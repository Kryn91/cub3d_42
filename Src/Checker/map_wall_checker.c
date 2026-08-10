/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 19:04:11 by apeterso          #+#    #+#             */
/*   Updated: 2026/08/10 19:04:25 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boolean.h"
#include "libft.h"
#include "map_wall_checker.h"
#include <stddef.h>

t_bool	is_valid_tile(char c)
{
	if (c == '0' || c == '1' || c == 'D' || c == 'E' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'O')
		return (TRUE);
	return (FALSE);
}

t_bool	check_zero(char **map, int x, int y)
{
	if (y == 0 || !map[y + 1])
		return (FALSE);
	if (x == 0 || x >= (int)ft_strlen(map[y]) - 1)
		return (FALSE);
	if (x >= (int)ft_strlen(map[y - 1]))
		return (FALSE);
	if (x >= (int)ft_strlen(map[y + 1]))
		return (FALSE);
	if (!is_valid_tile(map[y - 1][x]))
		return (FALSE);
	if (!is_valid_tile(map[y + 1][x]))
		return (FALSE);
	if (!is_valid_tile(map[y][x - 1]))
		return (FALSE);
	if (!is_valid_tile(map[y][x + 1]))
		return (FALSE);
	return (TRUE);
}

t_bool	check_wall(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->map.arr[y])
	{
		x = 0;
		while (game->map.arr[y][x])
		{
			if (game->map.arr[y][x] == '0' && check_zero(game->map.arr, x,
					y) == FALSE)
			{
				ft_putstr_fd("Error\nInvalid Wall on the Map\n", 2);
				return (FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}
