#ifndef CUB3D_H
# define CUB3D_H

# include "bool.h"
# include "libft.h"

# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 920

typedef struct s_img
{
	void	*img_ptr;
	void	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_texture
{
	t_img		img;
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
	double		mouse_x;
	double		mouse_y;
	double		rotation_angle;
}	t_player;

typedef struct s_fps
{
	double	last_frame;
	double	cap;
}	t_fps;

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

typedef struct s_enemy
{
	double		pos_x;
	double		pos_y;
	double		transform_x;
	double		transform_y;
	t_texture	tex;
}	t_enemy;

typedef struct s_input
{
    bool    A;
    bool    D;
    bool    W;
    bool    S;
}   t_input;

typedef struct s_time
{
    double  last_time;
    double  delta_time;
}   t_time;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
	t_input		input;
	t_list		*enemy_lst;
	t_time		delta_time;
	t_fps		fps;
	double		time;
	double		old_time;
	t_texture	hand[2];
	double		wall_dist_buf[SCREEN_WIDTH];
}	t_game;

void	parsing(int ac, char **av, t_game *game);

#endif
