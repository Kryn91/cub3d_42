#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_texture
{
	void		*img;
	char		*path;
	int			width;
	int			height;
}	t_texture;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	int			dir_x;
	int			dir_y;
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
}	t_game;

#endif
