#include <math.h>
#include <stdio.h>
#include "mlx.h"
#include "render.h"
#include "raycasting.h"

void	render_wall(t_game *game, t_ray *ray, int x, t_img *image)
{
	int		color;
	int		i;

	i = -1;
	while (++i < ray->wall_start)
		mlx_pixel_put_img(image, x, i, 0xFFF000);
	while (i < ray->wall_end)
	{
		color = *(unsigned int *)(ray->tex_img.addr + ray->tex_x
				* ray->tex_img.bpp / 8
				+ (int) ray->tex_y * ray->tex_img.size_line);
		mlx_pixel_put_img(image, x, i, color);
		ray->tex_y += ray->tex_step;
		i++;
	}
	while (i < game->screen_y)
	{
		mlx_pixel_put_img(image, x, i, 0x000FFF);
		i++;
	}
}

void	render_hand(t_game *game, t_img *img)
{
	int		pos_x;
	int		pos_y;

	pos_x = game->screen_x / 2.0 - game->hand[0].width * PIXEL_SIZE / 2.0;
	pos_y = game->screen_y - game->hand[0].height * PIXEL_SIZE;
	sprite_to_img(&game->hand[0], img, pos_x, pos_y);
}

int	render(t_game *game)
{
	int		x;
	t_ray	ray;
	t_img	img;

	x = -1;
	init_img(game, &img, game->screen_x, game->screen_y);
	while (++x <= game->screen_x - 1)
	{
		ray_init(game, &ray, x);
		side_dists_calc(game, &ray);
		ray_collision(game, &ray);
		line_calc(game, &ray);
		if (ray.wall_dist == 0)
			continue ;
		tex_calc(game, &ray);
		render_wall(game, &ray, x, &img);
	}
	render_minimap(game, &img);
	render_hand(game, &img);
	mlx_put_image_to_window(game->mlx, game->win, img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx, img.img_ptr);
	return (0);
}
