#include "cub3d.h"
#include "render.h"
#include "raycasting.h"

#include "stdio.h"

void	sort_enemies(t_list **enemy_lst)
{
	t_list	*cur;
	t_enemy	*enemy1;
	t_enemy	*enemy2;
	int		swap;
	t_enemy	*tmp;

	swap = 1;
	while (swap)
	{
		cur = *enemy_lst;
		swap = 0;
		while (cur->next)
		{
			enemy1 = (t_enemy *)cur->content;
			enemy2 = (t_enemy *)cur->next->content;
			if (enemy1->transform_y < enemy2->transform_y)
			{
				tmp = enemy1;
				cur->content = enemy2;
				cur->next->content = tmp;
				swap = 1;
			}
			cur = cur->next;
		}
	}
}

void	enemy_transform_calc(t_game *game)
{
	double	dist_x;
	double	dist_y;
	t_enemy	*enemy;
	t_list	*enemy_lst;
	double	inv_det;

	enemy_lst = game->enemy_lst;
	while (enemy_lst)
	{
		enemy = (t_enemy *) enemy_lst->content;
		dist_x = enemy->pos_x - game->player.pos_x;
		dist_y = enemy->pos_y - game->player.pos_y;
		inv_det = 1 / (game->player.plane_x * game->player.dir_y
				- game->player.plane_y * game->player.dir_x);
		enemy->transform_x = inv_det
			* (dist_x * game->player.dir_y - dist_y * game->player.dir_x);
		enemy->transform_y = inv_det
			* (-dist_x * game->player.plane_y + dist_y * game->player.plane_x);
		enemy_lst = enemy_lst->next;
	}
}

void	render_enemy(t_game *game, t_img *img)
{
	t_list			*enemy_lst;
	t_enemy			*enemy;
	int				sprite_height;
	int				sprite_width;
	int				sprite_start_x;
	int				sprite_start_y;
	int				sprite_mid_x;
	double			tex_x;
	double			tex_y;
	double			tex_step_x;
	double			tex_step_y;
	int				i;
	int				j;
	unsigned int	color;

	enemy_lst = game->enemy_lst;
	enemy_transform_calc(game);
	sort_enemies(&enemy_lst);
	while (enemy_lst)
	{
		enemy = (t_enemy *) enemy_lst->content;
		sprite_mid_x = SCREEN_WIDTH / 2 * (1 + enemy->transform_x / enemy->transform_y);
		// printf("%d\n", sprite_mid_x);
		if (enemy->transform_y <= 0.3)
		{
			enemy_lst = enemy_lst->next;
			continue ;
		}
		sprite_height = SCREEN_HEIGHT / enemy->transform_y;
		sprite_width = enemy->tex.width * sprite_height / enemy->tex.height;
		sprite_start_x = sprite_mid_x - sprite_width / 2;
		sprite_start_y = SCREEN_HEIGHT / 2 - sprite_height / 2;
		// printf("rstartx:%d, rstarty:%d\n", sprite_start_x, sprite_start_y);
		i = 0;
		tex_step_x = (double) enemy->tex.width / sprite_width;
		tex_step_y = (double) enemy->tex.height / sprite_height;
		// printf("spritew:%d, spriteh:%d\n", sprite_width, sprite_height);
		// sleep(1);
		tex_x = 0;
		while (i < sprite_width)
		{
			tex_y = 0;
			j = 0;
			if (sprite_start_x + i < 0 || sprite_start_x + i >= SCREEN_WIDTH)
			{
				i++;
				tex_x = tex_step_x * i;
				continue ;
			}
			if (game->wall_dist_buf[sprite_start_x + i] <= enemy->transform_y)
			{
				i++;
				tex_x = tex_step_x * i;
				continue ;
			}
			while (j < sprite_height)
			{
				// printf("posx:%f, posy:%f, startx:%d, starty:%d\n", enemy->pos_x, enemy->pos_y, sprite_start_x + i, sprite_start_y + j);
				if (sprite_start_x + i >= 0 && sprite_start_y + j >= 0 && sprite_start_x + i < SCREEN_WIDTH && sprite_start_y + j < SCREEN_HEIGHT)
				{
					color = *(unsigned int *)(enemy->tex.img.addr + enemy->tex.img.bpp / 8 * (int) tex_x + enemy->tex.img.size_line * (int) tex_y);
					if (color != 0xFF000000)
						mlx_pixel_put_img(img, sprite_start_x + i, sprite_start_y + j, color);
				}
				j++;
				tex_y = tex_step_y * j;
			}
			i++;
			tex_x = tex_step_x * i;
		}
		enemy_lst = enemy_lst->next;
	}
}
