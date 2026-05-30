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
	double		plane_x;
	double		plane_y;
}	t_player;

typedef struct s_map
{
	char		**arr;
	t_texture	walls[4];
	int			floor_color;
	int			ceiling_color;
	int			width;
	int			height;
}	t_map;

typedef struct s_ray
{
	double	cam_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_dist;
	double	line_length;
	int		wall_start;
	int		wall_end;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
	double		time;
	double		old_time;
	int			screen_x;
	int			screen_y;
}	t_game;

void    parsing(int ac, char **av);
#endif
