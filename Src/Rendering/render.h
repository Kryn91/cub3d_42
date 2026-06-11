#include "cub3d.h"

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

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
	int		line_length;
	int		wall_start;
	int		wall_end;
	int		step_x;
	int		step_y;
	int		side;
	int		tex_x;
	double	tex_y;
	int		color;
	double	tex_step;
	t_img	tex_img;
}	t_ray;

void	mlx_pixel_put_img(t_img *img, int x, int y, int color);
void	init_img(t_game *game, t_img *image);
void	render_minimap(t_game *game, t_img *image);
