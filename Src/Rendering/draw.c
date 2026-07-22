/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:41 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:46:42 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_entity_stripe(t_game *game, t_img *img, t_entity *entity,
	t_sprite_draw *d)
{
	unsigned int	color;
	int				j;
	t_texture		tex;

	tex = entity->tex[entity->frame];
	if (d->cur_x < 0 || d->cur_x >= SCREEN_WIDTH
		|| game->wall_dist_buf[d->cur_x] <= entity->transform_y)
		return ;
	j = 0;
	d->tex_y = 0;
	while (j < d->height)
	{
		d->cur_y = d->start_y + j;
		if (d->cur_x >= 0 && d->cur_y >= 0 && d->cur_x < SCREEN_WIDTH
			&& d->cur_y < SCREEN_HEIGHT)
		{
			color = *(unsigned int *)(tex.img.addr
					+ tex.img.bpp / 8 * (int) d->tex_x
					+ tex.img.size_line * (int) d->tex_y);
			if (color != 0xFF000000)
				mlx_pixel_put_img(img, d->cur_x, d->cur_y, color);
		}
		j++;
		d->tex_y = d->tex_step_y * j;
	}
}

void	draw_entity_sprite(t_game *game, t_img *img,
	t_entity *entity, double size_mod)
{
	t_sprite_draw	d;
	int				mid_x;
	int				i;
	t_texture		tex;

	tex = entity->tex[entity->frame];
	mid_x = SCREEN_WIDTH / 2 * (1 + entity->transform_x / entity->transform_y);
	d.height = SCREEN_HEIGHT / entity->transform_y * size_mod;
	d.width = tex.width * d.height / tex.height;
	d.start_x = mid_x - d.width / 2;
	d.start_y = SCREEN_HEIGHT / 2 - d.height / 2;
	d.tex_step_x = (double) tex.width / d.width;
	d.tex_step_y = (double) tex.height / d.height;
	d.tex_x = 0;
	i = 0;
	while (i < d.width)
	{
		d.cur_x = d.start_x + i;
		draw_entity_stripe(game, img, entity, &d);
		d.tex_x = d.tex_step_x * i;
		i++;
	}
}
