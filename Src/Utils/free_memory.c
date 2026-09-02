/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:47:28 by apeterso          #+#    #+#             */
/*   Updated: 2026/09/02 13:06:35 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_list.h"
#include "free_memory.h"
#include "mlx.h"

void	free_tab(size_t size, char **tab)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
}

void	free_array(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_split(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_walls_paths(t_game *game)
{
	if (game->map.walls[0].path)
	{
		free(game->map.walls[0].path);
		game->map.walls[0].path = NULL;
	}
	if (game->map.walls[1].path)
	{
		free(game->map.walls[1].path);
		game->map.walls[1].path = NULL;
	}
	if (game->map.walls[2].path)
	{
		free(game->map.walls[2].path);
		game->map.walls[2].path = NULL;
	}
	if (game->map.walls[3].path)
	{
		free(game->map.walls[3].path);
		game->map.walls[3].path = NULL;
	}
}

void	free_map(t_game *game)
{
	if (game->map.arr)
		free_array(game->map.arr);
	free_walls_paths(game);
	if (game->map.ceiling_parse)
	{
		free(game->map.ceiling_parse);
		game->map.ceiling_parse = NULL;
	}
	if (game->map.floor_parse)
	{
		free(game->map.floor_parse);
		game->map.floor_parse = NULL;
	}
}
