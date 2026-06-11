#ifndef READ_MAP_FILE_H
# define READ_MAP_FILE_H
# include "cub3d.h"

int	    open_file(char *map);
void	parse_map(char *map, t_game *game);

#endif