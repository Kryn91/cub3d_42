#include "cub3d.h"
#include "render.h"
#include "raycasting.h"

#include "stdio.h"

void	render_enemy(t_game *game, t_img *img)
{
	// (void) game;
	// (void) img;
	t_list			*enemy_lst;
	t_enemy			*enemy;
	double			dist_x;
	double			dist_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_height;
	int				sprite_width;
	int				sprite_start_x;
	int				sprite_start_y;
	double			tex_x;
	double			tex_y;
	double			tex_step_x;
	double			tex_step_y;
	int				i;
	int				j;
	unsigned int	color;

	enemy_lst = game->enemy_lst;
	while (enemy_lst)
	{
		enemy = (t_enemy *) enemy_lst->content;
		dist_x = enemy->pos_x - game->player.pos_x;
		dist_y = enemy->pos_y - game->player.pos_y;
		inv_det = 1 / (game->player.plane_x * game->player.dir_y
				- game->player.plane_y * game->player.dir_x);
		transform_x = inv_det
			* (dist_x * game->player.dir_y - dist_y * game->player.dir_x);
		transform_y = inv_det
			* (-dist_x * game->player.plane_y + dist_y * game->player.plane_x);
		printf("%f, %f\n", transform_x, transform_y);
		if (transform_y <= 0)
		{
			enemy_lst = enemy_lst->next;
			continue ;
		}
		sprite_height = SCREEN_HEIGHT / transform_y;
		sprite_width = enemy->tex.width * sprite_height / enemy->tex.height;
		sprite_start_x = SCREEN_WIDTH / 2 * (1 + transform_x / transform_y) - sprite_width / 2;
		sprite_start_y = SCREEN_HEIGHT / 2 - sprite_height / 2;
		// printf("rstartx:%d, rstarty:%d\n", sprite_start_x, sprite_start_y);
		i = 0;
		tex_step_x = (double) enemy->tex.width / sprite_width;
		tex_step_y = (double) enemy->tex.height / sprite_height;
		// printf("spritew:%d, spriteh:%d\n", sprite_width, sprite_height);
		// sleep(1);
		tex_x = 0;
		while (i <= sprite_width)
		{
			tex_y = 0;
			j = 0;
			while (j <= sprite_height)
			{
				// printf("posx:%f, posy:%f, startx:%d, starty:%d\n", enemy->pos_x, enemy->pos_y, sprite_start_x + i, sprite_start_y + j);
				if (sprite_start_x + i >= 0 && sprite_start_y + j >= 0 && sprite_start_x + i <= SCREEN_WIDTH && sprite_start_y + j <= SCREEN_HEIGHT)
				{
					color = *(unsigned int *)(enemy->tex.img.addr + enemy->tex.img.bpp / 8 * (int) tex_x + enemy->tex.img.size_line * (int) tex_y);
					if (color != 0xFF000000)
						mlx_pixel_put_img(img, sprite_start_x + i, sprite_start_y + j, color);
				}
				tex_y += tex_step_y;
				j++;
			}
			tex_x += tex_step_x;
			i++;
		}
		enemy_lst = enemy_lst->next;
	}
}
