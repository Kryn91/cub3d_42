#include "stdlib.h"
#include "read_map_file.h"
#include "free_memory.h"

size_t	count_lines(char *str)
{
	long	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] != 0)
			count++;
		i++;
	}
	count++;
	return (count);
}

size_t	count_width(char *map)
{
	size_t	i;

	i = 0;
	while (map [i] && map[i] != '\n')
		i++;
	return (i);
}

void	cpy_to_tab(int line, int width, char *tab, char *map)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (count < line && map[i])
	{
		if (map[i] == '\n')
			count++;
		i++;
	}
	while (j < width && map[i] && map[i] != '\n')
	{
		tab[j] = map[i];
		i++;
		j++;
	}
	tab[j] = '\0';
}

char	**vector_map(char *map)
{
	char	**map_tab;
	size_t	height;
	size_t	width;
	size_t	i;

	i = 0;
	height = count_lines(map);
	width = count_width(map);
	map_tab = malloc(sizeof(char *) * (height + 1));
	if (!map_tab)
		return (NULL);
	while (i < height)
	{
		map_tab[i] = malloc(sizeof(char) * (width + 1));
		if (!map_tab[i])
		{
			free_array(map_tab);
			return (NULL);
		}
		cpy_to_tab(i, width, map_tab[i], map);
		i++;
	}
	map_tab[height] = NULL;
	return (map_tab);
}

char	**create_map(char *file)
{
	char	*map;
	char	**map_tab;

	map = open_map(file);
	if (!map)
		exit(1);
    //checker la map
	map_tab = vector_map(map);
	if (!map_tab)
	{
		return (free(map), exit(1), NULL);
	}
	free(map);
	return (map_tab);
}