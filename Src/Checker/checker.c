/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:23:51 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 16:23:13 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "free_memory.h"
#include "map_checker.h"
#include <unistd.h>

t_bool	check_path(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (access(game->map.walls[i].path, F_OK) == -1)
		{
			ft_putstr_fd("Error\nIncorect path :", 2);
			ft_putstr_fd(game->map.walls[i].path, 2);
			ft_putstr_fd("\n", 2);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	checker(t_game *game)
{
	if (game->map.walls[0].path == NULL || game->map.walls[1].path == NULL
		|| game->map.walls[2].path == NULL || game->map.walls[3].path == NULL)
	{
		free_map(game);
		free(game);
		exit(1);
	}
	if (check_path(game) == FALSE)
	{
		free_map(game);
		free(game);
		exit(1);
	}
	if (check_map(game) == FALSE)
	{
		free_map(game);
		free(game);
		exit(1);
	}
}
