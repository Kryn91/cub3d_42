#include "cub3d.h"
#include "render.h"
#include "raycasting.h"
#include "delta_time.h"
#include "draw.h"
void	sort_entities(t_list **entity_lst)
{
	int			swap;
	t_list		*cur;
	t_entity	*entity1;
	t_entity	*entity2;
	t_entity	*tmp;

	swap = 1;
	if (!*entity_lst)
		return ;
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

void	render_projectile(t_game *game, t_img *img, t_entity *proj)
{
	double	time;

	if (proj->state == 0)
		return ;
	time = get_time();
	if (time - game->spell.last_frame_time > 200)
	{
		proj->frame = (proj->frame + 1) % 3;
		proj->last_frame_time = time;
	}
	draw_entity_sprite(game, img, proj, 0.5);
}

void	render_enemy(t_game *game, t_img *img, t_entity *enemy)
{
	if (enemy->state != 0 && enemy->transform_y > 0.3)
		draw_entity_sprite(game, img, enemy, 1);
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
		if (entity->type == PROJECTILE)
			render_projectile(game, img, entity);
		else
			render_enemy(game, img, entity);
		entity_lst = entity_lst->next;
	}
}
