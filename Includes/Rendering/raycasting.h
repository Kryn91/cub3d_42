#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"
# include "mlx.h"
# include <math.h>

typedef struct s_ray
{
	int		door;
	int		x;
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
	int		door_side;
	t_img	tex_img;
}	t_ray;

void	tex_calc(t_game *game, t_ray *ray);
void	tex_calc_door(t_game *game, t_ray *ray);
void	ray_init(t_game *game, t_ray *ray, int x);
void	ray_collision(t_game *game, t_ray *ray);
// void	door_collision(t_game *game, t_img *img, int x);
void	side_dists_calc(t_game *game, t_ray *ray);
void	line_calc(t_game *game, t_ray *ray, int x);
int		side_calc(t_ray *ray);


#endif
