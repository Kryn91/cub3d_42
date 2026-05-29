#ifndef CUB3D_H
# define CUB3D_H

#include "bool.h"

typedef struct s_texture
{
	void		*img;
	char		*path;
	int			width;
	int			height;
}	t_texture;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		cam_x;
	double		cam_y;
}	t_player;

typedef struct s_map
{
	char		**arr;
	t_texture	walls[4];
	int			floor_color;
	int			ceiling_color;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
	double		time;
	double		old_time;
}	t_game;

bool    parsing(int ac, char **av);
#endif
