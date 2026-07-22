/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:47 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:46:48 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "minimap.h"
#include <math.h>

void	minimap_pixel_pos(t_game *game, t_minimap_pixel *px)
{
	double	offset_x;
	double	offset_y;
	double	rot_offset_x;
	double	rot_offset_y;

	offset_x = px->x - MINIMAP_SIZE / 2.0;
	offset_y = px->y - MINIMAP_SIZE / 2.0;
	rot_offset_x = (offset_x * cos(game->player.rotation_angle))
		- (offset_y * sin(game->player.rotation_angle));
	rot_offset_y = (offset_x * sin(game->player.rotation_angle))
		+ (offset_y * cos(game->player.rotation_angle));
	px->map_x = game->player.pos_x - rot_offset_x / MINIMAP_TILE_SIZE;
	px->map_y = game->player.pos_y - rot_offset_y / MINIMAP_TILE_SIZE;
}

int	minimap_render_player(t_game *game, t_img *image, t_minimap_pixel *px)
{
	if (px->map_x >= game->player.pos_x - 0.1
		&& px->map_x <= game->player.pos_x + 0.1
		&& px->map_y >= game->player.pos_y - 0.1
		&& px->map_y <= game->player.pos_y + 0.1)
	{
		mlx_pixel_put_img
			(image, MINIMAP_POS_X + px->x, MINIMAP_POS_Y + px->y, 0x0000FF);
		return (1);
	}
	return (0);
}

void	minimap_pixel_render(t_game *game, t_img *image, t_minimap_pixel *px)
{
	if (px->map_y >= 0 && px->map_y < game->map.height && px->map_x >= 0
		&& px->map_x < ft_strlen(game->map.arr[(int)px->map_y]))
	{
		if (minimap_render_player(game, image, px))
			return ;
		if (game->map.arr[(int)px->map_y][(int)px->map_x] == '1')
			mlx_pixel_put_img
				(image, MINIMAP_POS_X + px->x, MINIMAP_POS_Y + px->y, 0x000000);
		else if (game->map.arr[(int)px->map_y][(int)px->map_x] == 'D')
			mlx_pixel_put_img
				(image, MINIMAP_POS_X + px->x, MINIMAP_POS_Y + px->y, 0x023100);
		else if (game->map.arr[(int)px->map_y][(int)px->map_x] == '0'
			|| game->map.arr[(int)px->map_y][(int)px->map_x] == 'O')
			mlx_pixel_put_img
				(image, MINIMAP_POS_X + px->x, MINIMAP_POS_Y + px->y, 0xFFFFFF);
		else if (game->map.arr[(int)px->map_y][(int)px->map_x] == ' ')
			mlx_pixel_put_img
				(image, MINIMAP_POS_X + px->x, MINIMAP_POS_Y + px->y, 0x1A1A1A);
		else
			mlx_pixel_put_img
				(image, MINIMAP_POS_X + px->x, MINIMAP_POS_Y + px->y, 0x101233);
	}
	else
		mlx_pixel_put_img
			(image, MINIMAP_POS_X + px->x, MINIMAP_POS_Y + px->y, 0x1A1A1A);
}

void	render_minimap(t_game *game, t_img *image)
{
	t_minimap_pixel	px;

	px.y = -1;
	while (++px.y < MINIMAP_SIZE)
	{
		px.x = -1;
		while (++px.x < MINIMAP_SIZE)
		{
			minimap_pixel_pos(game, &px);
			minimap_pixel_render(game, image, &px);
		}
	}
}
