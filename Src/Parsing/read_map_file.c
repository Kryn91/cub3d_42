#include "libft.h"
#include "get_next_line.h"
#include "cub3d.h"
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

void	read_texture(int fd, t_game *game)
{
	char	*line;

    line = get_next_line(fd);
    game->map.walls[0].path = ft_strtrim(line, "\n");
    free(line);
    line = get_next_line(fd);
    game->map.walls[1].path = ft_strtrim(line, "\n");
    free(line);
    line = get_next_line(fd);
    game->map.walls[2].path = ft_strtrim(line, "\n");
    free(line);
    line = get_next_line(fd);
    game->map.walls[3].path = ft_strtrim(line, "\n");
    free(line);
    line = get_next_line(fd);
    game->map.floor_parse = ft_strtrim(line, "\n");
    free(line);
    line = get_next_line(fd);
    game->map.ceiling_parse = ft_strtrim(line, "\n");
    free(line);
	game->map.floor_parse = get_next_line(fd);
	game->map.ceiling_parse = get_next_line(fd);
	/*
    printf("NO = %sSO = %sWE = %sEA = %s\nF  = %sC  = %s\n",
    game->map.walls[0].path,
    game->map.walls[1].path,
    game->map.walls[2].path,
    game->map.walls[3].path,
    game->map.floor_parse,
    game->map.ceiling_parse);
	*/
}

char	*open_map(char *map, t_game *game)
{
	int		fd;
	char	*map_read;
	char	*line_read;
	char	*temp;

	fd = open_file(map);
	read_texture(fd, game);
	map_read = ft_strdup("");
	temp = NULL;
	line_read = get_next_line(fd);
	while (line_read != NULL)
	{
		temp = ft_strjoin(map_read, line_read);
		free(line_read);
		free(map_read);
		if (!temp)
			return (close(fd), NULL);
		map_read = temp;
		line_read = get_next_line(fd);
	}
	close(fd);
	return (map_read);
}
