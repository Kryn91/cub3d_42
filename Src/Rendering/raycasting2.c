#include "raycasting.h"

void	tex_calc(t_game *game, t_ray *ray)
{
	double	wall_x;
	int		wall_side;

	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->dir_y * ray->wall_dist;
	else
		wall_x = game->player.pos_x + ray->dir_x * ray->wall_dist;
	wall_x -= floor(wall_x);
	wall_side = side_calc(ray);
	ray->tex_x = wall_x * game->map.walls[wall_side].width;
	ray->tex_step = (double) game->map.walls[wall_side].height
		/ ray->line_length;
	ray->tex_y = (ray->wall_start - game->screen_y / 2 + ray->line_length / 2)
		* ray->tex_step;
	ray->tex_img.addr = mlx_get_data_addr
		(game->map.walls[wall_side].img.img_ptr, &ray->tex_img.bpp,
			&ray->tex_img.size_line, &ray->tex_img.endian);
}
