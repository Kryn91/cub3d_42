#include "attack.h"
#include "door.h"
#include "mlx.h"
#include "delta_time.h"
#include "init_texture.h"
#include "colision.h"
#include "enemy_death.h"

void	handle_mouse(int button, int x, int y, void *param)
{
	(void) x;
	(void) y;
	if (button == 1)
		shoot((t_game *)param);
}

void	shoot(t_game *game)
{
	t_entity	*projectile;

	if (game->hand.frame == 1)
		return ;
	game->hand.frame = 1;
	game->hand.last_frame_time = get_time();
	if (get_time() - game->last_shoot_time < 500)
		return ;
	projectile = malloc(sizeof(t_entity));
	projectile->type = PROJECTILE;
	init_tex(game, &projectile->tex[0], "Assets/Spell/FlameProj0.xpm");
	init_tex(game, &projectile->tex[1], "Assets/Spell/FlameProj1.xpm");
	init_tex(game, &projectile->tex[2], "Assets/Spell/FlameProj2.xpm");
	projectile->pos_x = game->player.pos_x + game->player.dir_x;
	projectile->pos_y = game->player.pos_y + game->player.dir_y;
	projectile->spec.p_data.dir_x = game->player.dir_x;
	projectile->spec.p_data.dir_y = game->player.dir_y;
	projectile->state = 1;
	projectile->frame = 0;
	projectile->last_frame_time = get_time();
	ft_lstadd_front(&game->entity_lst, ft_lstnew(projectile));
	game->last_shoot_time = get_time();
}

t_col	projectile_enemy_col(t_game *game, double x, double y)
{
	t_list		*entity_lst;
	t_entity	*entity;

	entity_lst = game->entity_lst;
	while (entity_lst)
	{
		entity = (t_entity *)entity_lst->content;
		if (entity->type == ENEMY
			&& x >= entity->pos_x - entity->spec.e_data.hit_radius
			&& x <= entity->pos_x + entity->spec.e_data.hit_radius
			&& y >= entity->pos_y - entity->spec.e_data.hit_radius
			&& y <= entity->pos_y + entity->spec.e_data.hit_radius)
		{
			entity->spec.e_data.hp -= 25;
			if (entity->spec.e_data.hp <= 0)
				entity->state = 0;
			return (COL_ENEMY);
		}
		entity_lst = entity_lst->next;
	}
	return (COL_NONE);
}

t_col	projectile_colision(t_game *game, t_entity *projectile)
{
	double		x;
	double		y;
	t_door		*door;

	x = projectile->pos_x;
	y = projectile->pos_y;
	if ((int)x < 0 || (int)y < 0
		|| (int)x >= game->map.width || (int)y >= game->map.height)
		return (COL_WALL);
	if ((int)(x - ENEMY_RADIUS) < 0 || (int)(y - ENEMY_RADIUS) < 0
		|| (int)(x + ENEMY_RADIUS) >= game->map.width
		|| (int)(y + ENEMY_RADIUS) >= game->map.height)
		return (COL_WALL);
	if (check_wall_radius(x, y, game))
		return (COL_WALL);
	if (game->map.arr[(int)y][(int)x] == 'D')
	{
		door = find_door((int)x, (int)y, game);
		if (door == NULL || door->state != OPEN)
			return (COL_WALL);
	}
	return (projectile_enemy_col(game, x, y));
}

void	projectile_update(t_game *game)
{
	t_list		*entity_lst;
	t_entity	*entity;

	entity_lst = game->entity_lst;
	while (entity_lst)
	{
		entity = (t_entity *)entity_lst->content;
		if (entity->type == PROJECTILE)
		{
			entity->pos_x += entity->spec.p_data.dir_x * 0.6;
			entity->pos_y += entity->spec.p_data.dir_y * 0.6;
			if (projectile_colision(game, entity) != COL_NONE)
				entity->state = 0;
		}
		entity_lst = entity_lst->next;
	}
	free_dead_enemies(game);
}
