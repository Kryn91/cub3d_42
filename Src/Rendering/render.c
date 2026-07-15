#include <math.h>
#include <stdio.h>
#include "mlx.h"
#include "render.h"
#include "raycasting.h"
#include "cub3d.h"
#include "delta_time.h"
#include "render_health_bar.h"

void	render_door(t_game *game, t_ray *ray, t_img *image, int x)
{
	int	color;
	int	i;

	i = ray->wall_start;
	while (i < ray->wall_end)
	{
		// printf("%d, %f\n", ray->tex_x, ray->tex_y);
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

void	render_hand(t_game *game, t_img *img)
{
	t_vec	pos;

	if (game->hand.frame == 0)
	{
		pos.x = SCREEN_WIDTH * 0.05;
		pos.y = SCREEN_HEIGHT
			- game->hand.tex[game->hand.frame].height * PIXEL_SIZE * 1;
		sprite_to_img(&game->hand.tex[game->hand.frame], img, pos, 1);
	}
	else
	{
		pos.x = SCREEN_WIDTH * 0.15;
		pos.y = SCREEN_HEIGHT
			- game->hand.tex[game->hand.frame].height * PIXEL_SIZE * 0.9;
		sprite_to_img(&game->hand.tex[game->hand.frame], img, pos, 0.9);
	}
	if (game->hand.frame == 1
		&& get_time() - game->hand.last_frame_time > 490)
	{
		game->hand.frame = 0;
		game->hand.last_frame_time = get_time();
	}
}


void render_spell(t_game *game, t_img *img)
{
	t_vec	pos;

	if (get_time() - game->last_shoot_time < 510)
		return ;
	if (game->spell.frame == 0)
	{
		pos.x = SCREEN_WIDTH * 0.25;
		pos.y = SCREEN_HEIGHT - 88
			- game->spell.tex[game->spell.frame].height * PIXEL_SIZE * 3;
		sprite_to_img(&game->spell.tex[game->spell.frame], img, pos, 3);
	}
	else if (game->spell.frame == 1)
	{
		pos.x = SCREEN_WIDTH * 0.25;
		pos.y = SCREEN_HEIGHT - 88
			- game->spell.tex[game->spell.frame].height * PIXEL_SIZE * 3;
		sprite_to_img(&game->spell.tex[game->spell.frame], img, pos, 3);
	}
	else
	{
		pos.x = SCREEN_WIDTH * 0.25;
		pos.y = SCREEN_HEIGHT - 88
			- game->spell.tex[game->spell.frame].height * PIXEL_SIZE * 3;
		sprite_to_img(&game->spell.tex[game->spell.frame], img, pos, 3);
	}
	if (get_time() - game->spell.last_frame_time > 200)
	{
		game->spell.frame = (game->spell.frame + 1) % 3;
		game->spell.last_frame_time = get_time();
	}
}


void	render_scene(t_game *game, t_ray *ray, t_img *img, int x)
{
	while (++x <= SCREEN_WIDTH - 1)
	{
		ray_init(game, ray, x);
		side_dists_calc(game, ray);
		ray_collision(game, ray);
		line_calc(game, ray, x);
		if (ray->wall_dist <= 0)
			continue ;
		tex_calc(game, ray);
		render_walls(game, ray, x, img);
	}
}

int	render(t_game *game)
{
	int		x;
	t_ray	ray;
	t_img	img;

	x = -1;
	init_img(game, &img, SCREEN_WIDTH, SCREEN_HEIGHT);
	render_scene(game, &ray, &img, x);
	render_minimap(game, &img);
	render_entity(game, &img);
	render_hand(game, &img);
	render_spell(game, &img);
	render_health_bar(game, &img);
	mlx_put_image_to_window(game->mlx, game->win, img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx, img.img_ptr);
	return (0);
}
