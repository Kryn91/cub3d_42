#include "cub3d.h"
#include "render.h"
#include "raycasting.h"

#include "stdio.h"

void	sort_entities(t_list **entity_lst)
{
	int			swap;
	t_list		*cur;
	t_entity	*entity1;
	t_entity	*entity2;
	t_entity	*tmp;

	swap = 1;
	while (swap)
	{
		cur = *entity_lst;
		swap = 0;
		while (cur->next)
		{
			entity1 = (t_entity *)cur->content;
			entity2 = (t_entity *)cur->next->content;
			if (entity1->transform_y < entity2->transform_y)
			{
				tmp = entity1;
				cur->content = entity2;
				cur->next->content = tmp;
				swap = 1;
			}
			cur = cur->next;
		}
	}
}

void	entity_transform_calc(t_game *game)
{
	double		dist_x;
	double		dist_y;
	t_entity	*entity;
	t_list		*entity_lst;
	double		inv_det;

	entity_lst = game->entity_lst;
	while (entity_lst)
	{
		entity = (t_entity *) entity_lst->content;
		dist_x = entity->pos_x - game->player.pos_x;
		dist_y = entity->pos_y - game->player.pos_y;
		inv_det = 1 / (game->player.plane_x * game->player.dir_y
				- game->player.plane_y * game->player.dir_x);
		entity->transform_x = inv_det
			* (dist_x * game->player.dir_y - dist_y * game->player.dir_x);
		entity->transform_y = inv_det
			* (-dist_x * game->player.plane_y + dist_y * game->player.plane_x);
		entity_lst = entity_lst->next;
	}
}

void	draw_entity_stripe(t_game *game, t_img *img, t_entity *entity,
	t_sprite_draw *d)
{
	unsigned int	color;
	int				j;

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
			color = *(unsigned int *)(entity->tex.img.addr
					+ entity->tex.img.bpp / 8 * (int) d->tex_x
					+ entity->tex.img.size_line * (int) d->tex_y);
			if (color != 0xFF000000)
				mlx_pixel_put_img(img, d->cur_x, d->cur_y, color);
		}
		j++;
		d->tex_y = d->tex_step_y * j;
	}
}

void	draw_entity_sprite(t_game *game, t_img *img, t_entity *entity)
{
	t_sprite_draw	d;
	int				mid_x;
	int				i;


	mid_x = SCREEN_WIDTH / 2 * (1 + entity->transform_x / entity->transform_y);
	d.height = SCREEN_HEIGHT / entity->transform_y;
	d.width = entity->tex.width * d.height / entity->tex.height;
	d.start_x = mid_x - d.width / 2;
	d.start_y = SCREEN_HEIGHT / 2 - d.height / 2;
	d.tex_step_x = (double) entity->tex.width / d.width;
	d.tex_step_y = (double) entity->tex.height / d.height;
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

void	render_entity(t_game *game, t_img *img)
{
	t_list		*entity_lst;
	t_entity	*entity;

	entity_transform_calc(game);
	entity_lst = game->entity_lst;
	sort_entities(&entity_lst);
	while (entity_lst)
	{
		entity = (t_entity *) entity_lst->content;
		if (entity->state != 0 && entity->transform_y > 0.3)
			draw_entity_sprite(game, img, entity);
		entity_lst = entity_lst->next;
	}
}
