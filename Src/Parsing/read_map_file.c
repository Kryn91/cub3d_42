#include "libft.h"
#include "get_next_line.h"

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

char	*open_map(char *map)
{
	int		fd;
	char	*map_read;
	char	*line_read;
	char	*temp;

	fd = open_file(map);
	map_read = ft_strdup("");
	temp = NULL;
	line_read = get_next_line(fd);
	while (line_read != NULL)
	{
		temp = ft_strjoin(map_read, line_read);
		free(line_read);
		free(map_read);
		if (!temp)
			return (NULL);
		map_read = temp;
		line_read = get_next_line(fd);
	}
	close(fd);
	return (map_read);
}