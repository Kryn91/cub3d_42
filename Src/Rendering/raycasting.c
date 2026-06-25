#include "render.h"

void	ray_init(t_game *game, t_ray *ray, int x)
{
	ray->x = x;
	ray->cam_x = 2 * x / (double)SCREEN_WIDTH - 1;
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
	ray->door_side = -1;
	ray->door = 0;
}

int	door_calc_render_validity(t_game *game, t_ray *ray, double *door_x)
{
	if (ray->side != ray->door_side)
		return (0);
	if (ray->door_side == 0)
	{
		ray->wall_dist = fabs(ray->side_dist_x - ray->delta_dist_x / 2.0);
		*door_x = game->player.pos_y + ray->dir_y * ray->wall_dist;
		if (*door_x < ray->map_y || *door_x > ray->map_y + 1.0)
			return (0);
	}
	else
	{
		ray->wall_dist = fabs(ray->side_dist_y - ray->delta_dist_y / 2.0);
		*door_x = game->player.pos_x + ray->dir_x * ray->wall_dist;
		if (*door_x < ray->map_x || *door_x > ray->map_x + 1.0)
			return (0);
	}
	return (1);
}

int	door_check(t_game *game, t_ray *ray)
{
	double	door_x;
	t_door	*door;

	if (game->map.arr[ray->map_y][ray->map_x - 1] == '1')
		ray->door_side = 1;
	else
		ray->door_side = 0;
	if (!door_calc_render_validity(game, ray, &door_x))
		return (0);
	door_x -= floor(door_x);
	door = game->door;
	while (door)
	{
		if (ray->map_x == door->x && ray->map_y == door->y)
		{
			if (door_x < door->progress)
			{
				ray->door = 1;
				return (1);
			}
			break ;
		}
		door = door->next;
	}
	return (0);
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
		if (game->map.arr[ray->map_y][ray->map_x] == 'D')
		{
			if (door_check(game, ray))
				break ;
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

void	line_calc(t_game *game, t_ray *ray, int x)
{
	if (ray->door == true)
	{
		if (ray->door_side == 0)
			ray->wall_dist = fabs(ray->side_dist_x - (ray->delta_dist_x / 2.0));
		else
			ray->wall_dist = fabs(ray->side_dist_y - (ray->delta_dist_y / 2.0));
	}
	else
	{
		if (ray->side == 0)
			ray->wall_dist = fabs(ray->side_dist_x - ray->delta_dist_x);
		else
			ray->wall_dist = fabs(ray->side_dist_y - ray->delta_dist_y);
	}
	game->wall_dist_buf[x] = ray->wall_dist;
	if (ray->wall_dist <= 0)
		return ;
	ray->line_length = (double) SCREEN_HEIGHT / ray->wall_dist;
	ray->wall_start = SCREEN_HEIGHT / 2 - ray->line_length / 2;
	ray->wall_end = SCREEN_HEIGHT / 2 + ray->line_length / 2;
	if (ray->wall_start < 0)
		ray->wall_start = 0;
	if (ray->wall_end > SCREEN_HEIGHT)
		ray->wall_end = SCREEN_HEIGHT - 1;
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
