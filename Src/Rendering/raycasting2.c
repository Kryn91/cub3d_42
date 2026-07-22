/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:57 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:46:58 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "cub3d.h"
#include "mlx.h"

void	line_calc(t_game *game, t_ray *ray, int x)
{
	if (ray->door)
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

void	door_tex_calc(t_game *game, t_ray *ray)
{
	ray->tex_x = (int)((ray->door->progress - ray->door_x)
			*game->map.walls[0].width);
	ray->tex_step = (double) game->map.walls[0].height
		/ ray->line_length;
}

void	tex_calc(t_game *game, t_ray *ray)
{
	double	wall_x;
	int		wall_side;

	if (ray->door)
		door_tex_calc(game, ray);
	else
	{
		if (ray->side == 0)
			wall_x = game->player.pos_y + ray->dir_y * ray->wall_dist;
		else
			wall_x = game->player.pos_x + ray->dir_x * ray->wall_dist;
		wall_x -= floor(wall_x);
		wall_side = side_calc(ray);
		ray->tex_x = wall_x * game->map.walls[wall_side].width;
		ray->tex_img.addr = mlx_get_data_addr
			(game->map.walls[wall_side].img.img_ptr, &ray->tex_img.bpp,
				&ray->tex_img.size_line, &ray->tex_img.endian);
		ray->tex_step = (double) game->map.walls[wall_side].height
			/ ray->line_length;
	}
	ray->tex_y = (ray->wall_start - SCREEN_HEIGHT / 2 + ray->line_length / 2)
		* ray->tex_step;
}
