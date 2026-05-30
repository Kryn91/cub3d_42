#include "libft.h"
#include "cub3d.h"
#include "mlx.h"
#include "bool.h"
#include <math.h>
#include <stdio.h>

void	init_test(t_game *game);

void	ray_dir_calc(t_game *game, t_ray *ray)
{
	int	x;

	x = -1;
	while (++x <= game->screen_x)
	{
		ray->cam_x = 2 * x / (double)game->screen_x - 1;
		ray->dir_x = game->player.dir_x + game->player.plane_x * ray->cam_x;
		ray->dir_y = game->player.dir_y + game->player.plane_y * ray->cam_x;

		ray->delta_dist_x = fabs(1 / ray->dir_x);
		ray->delta_dist_y = fabs(1 / ray->dir_y);

		ray->side_dist_x = 0;
		ray->side_dist_y = 0;
		ray->map_x = (int) game->player.pos_x;
		ray->map_y = (int) game->player.pos_y;
		if (ray->dir_x < 0)
		{
			ray->step_x = -1;
			ray->side_dist_x = (game->player.pos_x - ray->map_x) * ray->delta_dist_x;
		}
		else
		{
			ray->step_x = 1;
			ray->side_dist_x = (ray->map_x + 1 - game->player.pos_x) * ray->delta_dist_x;
		}
		if (ray->dir_y < 0)
		{
			ray->step_y = -1;
			ray->side_dist_y = (game->player.pos_y - ray->map_y) * ray->delta_dist_y;
		}
		else
		{
			ray->step_y = 1;
			ray->side_dist_y = (ray->map_y + 1 - game->player.pos_y) * ray->delta_dist_y;
		}
		ray->hit = 0;
		while (!ray->hit)
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
			if (game->map.arr[ray->map_y][ray->map_x] == '1')
			{
				ray->hit = 1;
				printf("hit wall at (%d, %d)\n", ray->map_x, ray->map_y);
			}
		}
		if (ray->side == 0)
			ray->wall_dist = ray->side_dist_x - ray->delta_dist_x;
		else
			ray->wall_dist = ray->side_dist_y - ray->delta_dist_y;
		ray->line_length = game->screen_y / ray->wall_dist;
		ray->wall_start = (game->screen_y / 2) - (ray->line_length / 2);
		if (ray->wall_start < 0)
			ray->wall_start = 0;
		if (ray->wall_end > game->screen_y)
			ray->wall_end = game->screen_y - 1;
		ray->wall_end = (game->screen_y / 2) + (ray->line_length / 2);
		// if (x == 0 || x == game->screen_x || x == game->screen_x / 2)
		// 	printf("camX :%f, dirX :%f, dirY:%f, deltaDistX:%f, deltaDistY:%f\n",
		// 		ray->cam_x, ray->dir_x, ray->dir_y, ray->delta_dist_x, ray->delta_dist_y);
		while (ray->wall_start != ray->wall_end)
		{
			mlx_pixel_put(game->mlx, game->win, x, ray->wall_start, 0xFFFFFF);
			printf("start :%d, end :%d\n", ray->wall_start, ray->wall_end);
			ray->wall_start++;
		}
	}
	// mlx_loop_end(game->mlx);
}

int	ray(t_game *game)
{
	t_ray	ray;

	ray_dir_calc(game, &ray);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	parsing(ac, av);
	game.mlx = mlx_init();
	init_test(&game);
	game.win = mlx_new_window(game.mlx, game.screen_x, game.screen_y, "cub3d");
	mlx_loop_hook(game.mlx, ray, &game);
	mlx_loop(game.mlx);
	return (0);
}
