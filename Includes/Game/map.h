#ifndef MAP_H
# define MAP_H

# include "render.h"

typedef struct s_map
{
	char		**arr;
	t_texture	walls[4];
	int			floor_color;
	char		*floor_parse;
	int			ceiling_color;
	char		*ceiling_parse;
	int			width;
	int			height;
}	t_map;

#endif
