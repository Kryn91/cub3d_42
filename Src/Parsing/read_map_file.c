#include "boolean.h"
#include "cub3d.h"
#include "free_memory.h"
#include "get_next_line.h"
#include "libft.h"
#include "read_map_file.h"
#include "texture_parser.h"
#include <stdio.h>
#include "check_map.h"

int	open_file(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nInvalid file", 2);
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

void	parse_map_line(char *line, t_game *game,
		t_bool *in_map, t_bool *map_finished)
{
	if (*in_map == FALSE)
	{
		if (is_empty_line(line))
        return ;
		if (is_texture(line))
			handle_texture(line, game);
		if (is_map_line(line))
			*in_map = TRUE;
	}
	if (*in_map == TRUE)
	{
		if (is_empty_line(line))
			*map_finished = TRUE;
		else
		{
			if (*map_finished)
			{
				printf("Error: empty line inside or after the map\n");
				free_map(game);
				free(game);
				exit(EXIT_FAILURE);
			}
			game->map.arr = add_map_line(game->map.arr, line);
		}
	}
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
		parse_map_line(line, game, &in_map, &map_finished);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
