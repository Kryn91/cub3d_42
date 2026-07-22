/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:23:34 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:33:25 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "map_checker.h"
#include "map_solver.h"

t_bool	check_valid_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->arr[i])
	{
		j = 0;
		while (map->arr[i][j])
		{
			if (map->arr[i][j] != '1' && map->arr[i][j] != '0'
				&& map->arr[i][j] != 'N' && map->arr[i][j] != 'S'
				&& map->arr[i][j] != 'E' && map->arr[i][j] != 'W'
				&& map->arr[i][j] != ' ' && map->arr[i][j] != 'D'
				&& map->arr[i][j] != 'O')
			{
				ft_putstr_fd("Error\nInvalid map char :", 2);
				ft_putchar_fd(map->arr[i][j], 2);
				ft_putchar_fd('\n', 2);
				return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool	check_player_count(t_map *map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map->arr[i])
	{
		j = 0;
		while (map->arr[i][j])
		{
			if (map->arr[i][j] == 'N' || map->arr[i][j] == 'S'
				|| map->arr[i][j] == 'E' || map->arr[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (TRUE);
	else if (count > 1)
		ft_putstr_fd("Error\nToo Much player\n", 2);
	else
		ft_putstr_fd("Error\nPlayer is needed", 2);
	return (FALSE);
}

t_bool	check_map(t_game *game)
{
	if (game->map.width > MAX_MAP_SIZE || game->map.height > MAX_MAP_SIZE)
		return (ft_putstr_fd("Error\nMap too high\n", 2), FALSE);
	if (check_valid_char(&game->map) == FALSE)
		return (FALSE);
	if (check_player_count(&game->map) == FALSE)
		return (FALSE);
	if (map_solver(game) == FALSE)
		return (FALSE);
	return (TRUE);
}
