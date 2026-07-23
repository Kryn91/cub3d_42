/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <kealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:31 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/23 21:09:32 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boolean.h"
#include "color_parser.h"
#include "cub3d.h"
#include "libft.h"
#include "read_map_file.h"
#include <stdio.h>

t_bool	check_cub(char *av)
{
	size_t	i;

	i = ft_strlen(av) - 1;
	if (av[i] != 'b')
		return (ft_putstr_fd("Error\n.cub required", 2), FALSE);
	i--;
	if (av[i] != 'u')
		return (ft_putstr_fd("Error\n.cub required", 2), FALSE);
	i--;
	if (av[i] != 'c')
		return (ft_putstr_fd("Error\n.cub required", 2), FALSE);
	i--;
	if (av[i] != '.')
		return (ft_putstr_fd("Error\n.cub required", 2), FALSE);
	return (TRUE);
}

t_bool	check_valid_arg(int ac, char **av, t_game *game)
{
	if (ac != 2 || av[1][0] == '\0')
		return (FALSE);
	if (check_cub(av[1]) == FALSE)
	{
		free(game);
		exit(1);
	}
	return (TRUE);
}

void	init_map_size(t_map *map)
{
	int	i;
	int	len;
	int	max_len;

	max_len = 0;
	i = 0;
	while (map->arr[i])
	{
		len = ft_strlen(map->arr[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	map->width = max_len;
	map->height = i;
}

void	parsing(int ac, char **av, t_game *game)
{
	if (check_valid_arg(ac, av, game) == FALSE)
		exit(1);
	parse_map(av[1], game);
	init_map_size(&game->map);
	color_parser(game);
	if (!game->map.arr)
		exit(1);
}
