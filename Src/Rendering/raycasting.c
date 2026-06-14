#include "raycasting.h"

void	ray_init(t_game *game, t_ray *ray, int x)
{
	ray->cam_x = 2 * x / (double)game->screen_x - 1;
	ray->dir_x = game->player.dir_x + game->player.plane_x * ray->cam_x;
	ray->dir_y = game->player.dir_y + game->player.plane_y * ray->cam_x;
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->map_x = (int) game->player.pos_x;
	ray->map_y = (int) game->player.pos_y;
	ray->side = 0;
}

void	ray_collision(t_game *game, t_ray *ray)
{
	while (ray->map_x >= 0 && ray->map_x < game->map.width
		&& ray->map_y >= 0 && ray->map_y < game->map.height
		&& game->map.arr[ray->map_y][ray->map_x] != '1')
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->map_x += ray->step_x;
			ray->side_dist_x += ray->delta_dist_x;
			ray->side = 0;
		}
		else
		{
			ray->map_y += ray->step_y;
			ray->side_dist_y += ray->delta_dist_y;
			ray->side = 1;
		}
	}
}

void	side_dists_calc(t_game *game, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - game->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1 - game->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	line_calc(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = fabs(ray->side_dist_x - ray->delta_dist_x);
	else
		ray->wall_dist = fabs(ray->side_dist_y - ray->delta_dist_y);
	if (ray->wall_dist == 0)
		return ;
	ray->line_length = (double) game->screen_y / ray->wall_dist;
	ray->wall_start = game->screen_y / 2 - ray->line_length / 2;
	ray->wall_end = game->screen_y / 2 + ray->line_length / 2;
	if (ray->wall_start < 0)
		ray->wall_start = 0;
	if (ray->wall_end > game->screen_y)
		ray->wall_end = game->screen_y - 1;
}

int	side_calc(t_ray *ray)
{
	if (ray->side == 0 && ray->dir_x >= 0)
		return (0);
	if (ray->side == 0 && ray->dir_x < 0)
		return (1);
	if (ray->side == 1 && ray->dir_y >= 0)
		return (2);
	if (ray->side == 1 && ray->dir_y < 0)
		return (3);
	return (0);
}

