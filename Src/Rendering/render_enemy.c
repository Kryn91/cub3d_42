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

void	draw_enemy_stripe(t_game *game, t_img *img, t_enemy *enemy,
	t_sprite_draw *d)
{
	unsigned int	color;
	int				j;

	if (d->cur_x < 0 || d->cur_x >= SCREEN_WIDTH
		|| game->wall_dist_buf[d->cur_x] <= enemy->transform_y)
		return ;
	j = 0;
	d->tex_y = 0;
	while (j < d->height)
	{
		d->cur_y = d->start_y + j;
		if (d->cur_x >= 0 && d->cur_y >= 0 && d->cur_x < SCREEN_WIDTH
			&& d->cur_y < SCREEN_HEIGHT)
		{
			color = *(unsigned int *)(enemy->tex.img.addr
					+ enemy->tex.img.bpp / 8 * (int) d->tex_x
					+ enemy->tex.img.size_line * (int) d->tex_y);
			if (color != 0xFF000000)
				mlx_pixel_put_img(img, d->cur_x, d->cur_y, color);
		}
		j++;
		d->tex_y = d->tex_step_y * j;
	}
}

void	draw_enemy_sprite(t_game *game, t_img *img, t_enemy *enemy)
{
	t_sprite_draw	d;
	int				mid_x;
	int				i;


	mid_x = SCREEN_WIDTH / 2 * (1 + enemy->transform_x / enemy->transform_y);
	d.height = SCREEN_HEIGHT / enemy->transform_y;
	d.width = enemy->tex.width * d.height / enemy->tex.height;
	d.start_x = mid_x - d.width / 2;
	d.start_y = SCREEN_HEIGHT / 2 - d.height / 2;
	d.tex_step_x = (double) enemy->tex.width / d.width;
	d.tex_step_y = (double) enemy->tex.height / d.height;
	d.tex_x = 0;
	i = 0;
	while (i < d.width)
	{
		d.cur_x = d.start_x + i;
		draw_enemy_stripe(game, img, enemy, &d);
		d.tex_x = d.tex_step_x * i;
		i++;
	}
}

void	render_enemy(t_game *game, t_img *img)
{
	t_list			*enemy_lst;
	t_enemy			*enemy;

	enemy_transform_calc(game);
	enemy_lst = game->enemy_lst;
	sort_enemies(&enemy_lst);
	while (enemy_lst)
	{
		enemy = (t_enemy *) enemy_lst->content;
		if (enemy->transform_y > 0.3)
			draw_enemy_sprite(game, img, enemy);
		enemy_lst = enemy_lst->next;
	}
}
