#include "cub3d.h"
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

t_bool	is_valid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	parse_map(char *map, t_game *game)
{
	int		fd;
	char	*line_read;

	fd = open_file(map);
	if (fd == -1)
		return ;
	line_read = get_next_line(fd);
	while (line_read != NULL)
	{
		if (is_texture(line_read))
			handle_texture(line_read, game);
		else if (is_valid_line(line_read))
			game->map.arr = add_map_line(game->map.arr, line_read);
		free(line_read);
		line_read = get_next_line(fd);
	}
	close(fd);
}
