/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:47:02 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:47:04 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_walls.h"

void	render_door(t_game *game, t_ray *ray, t_img *image, int x)
{
	int	color;
	int	i;

	i = ray->wall_start;
	while (i < ray->wall_end)
	{
		color = *(unsigned int *)(game->door_texture.img.addr + ray->tex_x
				* game->map.walls[0].img.bpp / 8
				+ (int) ray->tex_y * game->door_texture.img.size_line);
		mlx_pixel_put_img(image, x, i, color);
		ray->tex_y += ray->tex_step;
		i++;
	}
}

void	render_wall(t_ray *ray, int x, t_img *image)
{
	int	color;
	int	i;

	i = ray->wall_start;
	while (i < ray->wall_end)
	{
		color = *(unsigned int *)(ray->tex_img.addr + ray->tex_x
				* ray->tex_img.bpp / 8
				+ (int) ray->tex_y * ray->tex_img.size_line);
		mlx_pixel_put_img(image, x, i, color);
		ray->tex_y += ray->tex_step;
		i++;
	}
}

void	render_walls(t_game *game, t_ray *ray, int x, t_img *image)
{
	int		i;

	i = 0;
	while (i < ray->wall_start)
	{
		mlx_pixel_put_img(image, x, i, game->map.ceiling_color);
		i++;
	}
	if (ray->door)
		render_door(game, ray, image, x);
	else
		render_wall(ray, x, image);
	i = ray->wall_end;
	while (i < SCREEN_HEIGHT)
	{
		mlx_pixel_put_img(image, x, i, game->map.floor_color);
		i++;
	}
}
