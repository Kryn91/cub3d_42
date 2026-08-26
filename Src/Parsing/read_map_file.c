/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:24:19 by kealves-          #+#    #+#             */
/*   Updated: 2026/08/26 17:50:22 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boolean.h"
#include "check_map.h"
#include "cub3d.h"
#include "free_game.h"
#include "free_memory.h"
#include "get_next_line.h"
#include "libft.h"
#include "read_map_file.h"
#include "texture_parser.h"
#include <stdio.h>

int	open_file(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nInvalid file\n", 2);
		exit(1);
	}
	return (fd);
}

char	**add_map_line(char **map, char *line)
{
	char	**new_map;
	size_t	i;
	size_t	len;

	len = 0;
	while (map && map[len])
		len++;
	new_map = malloc(sizeof(char *) * (len + 2));
	if (!new_map)
		return (perror("malloc"), NULL);
	i = 0;
	while (map && map[i])
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = ft_strtrim(line, "\n");
	if (!new_map[i])
		return (free(new_map), perror("strdup"), NULL);
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}

int	check_before_map(char *line, t_game *game, t_bool *in_map)
{
	if (is_empty_line(line))
		return (0);
	if (is_texture(line))
	{
		if (handle_texture(line, game) == FALSE)
			return (1);
		return (0);
	}
	if (is_map_line(line))
	{
		*in_map = TRUE;
		return (0);
	}
	ft_putstr_fd("Error\nInvalid identifier before map\n", 2);
	return (1);
}

int	parse_map_line(char *line, t_game *game, t_bool *in_map,
		t_bool *map_finished)
{
	if (*in_map == FALSE)
	{
		if (check_before_map(line, game, in_map))
			return (1);
	}
	if (*in_map == TRUE)
	{
		if (is_empty_line(line))
			*map_finished = TRUE;
		else
		{
			if (*map_finished)
			{
				return (printf("Error\nempty line inside or after the map\n"),
					1);
			}
			game->map.arr = add_map_line(game->map.arr, line);
		}
	}
	return (0);
}

void	parse_map(char *map, t_game *game)
{
	int		fd;
	char	*line;
	t_bool	in_map;
	t_bool	map_finished;

	in_map = FALSE;
	map_finished = FALSE;
	fd = open_file(map);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		if (parse_map_line(line, game, &in_map, &map_finished) == 1)
		{
			free(line);
			finish_gnl(fd);
			free_game(game);
			exit(1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
