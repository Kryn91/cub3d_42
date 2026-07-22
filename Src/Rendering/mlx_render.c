/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:50 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:46:51 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "mlx.h"
#include "cub3d.h"
#include "vector_manipulation.h"

void	mlx_pixel_put_img(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + y * img->size_line + x * (img->bpp / 8);
	*(unsigned int *)pixel = color;
}

void	init_img(t_game *game, t_img *img, int width, int height)
{
	img->img_ptr = mlx_new_image(game->mlx, width, height);
	img->addr = mlx_get_data_addr
		(img->img_ptr, &img->bpp, &img->size_line, &img->endian);
}

void	draw_pixels(t_img *img, unsigned int color, t_vec pos, double size_mod)
{
	int	i;
	int	j;

	j = -1;
	while (++j < PIXEL_SIZE * size_mod)
	{
		i = -1;
		while (++i < PIXEL_SIZE * size_mod)
		{
			if ((int)pos.x + i < 0 || (int)pos.y + j < 0
				|| (int)pos.x + i > SCREEN_WIDTH
				|| (int)pos.y + i > SCREEN_HEIGHT)
				continue ;
			mlx_pixel_put_img(img, (int)pos.x + i, (int)pos.y + j, color);
		}
	}
}

void	sprite_to_img(t_texture *tex, t_img *img, t_vec pos, double size_mod)
{
	int				x;
	int				y;
	unsigned int	color;
	t_vec			draw_pos;

	y = -1;
	while (++y < tex->height)
	{
		x = -1;
		while (++x < tex->width)
		{
			color = *(unsigned int *)(tex->img.addr + y * tex->img.size_line
					+ x * (tex->img.bpp / 8));
			if (color == 0xFF000000)
				continue ;
			draw_pos.x = pos.x + x * PIXEL_SIZE * size_mod;
			draw_pos.y = pos.y + y * PIXEL_SIZE * size_mod;
			draw_pixels(img, color, draw_pos, size_mod);
		}
	}
}
