#include "attack.h"
#include "door.h"

void	handle_mouse(int button, int x, int y, void *param)
{
	(void) x;
	(void) y;
	if (button == 1)
		shoot((t_game *)param);
}
void	shoot(t_game *game)
{
	game->hand_frame = 1;
	if (game->projectile->state == 1)
		return ;
	game->projectile->pos_x = game->player.pos_x + game->player.dir_x;
	game->projectile->pos_y = game->player.pos_y + game->player.dir_y;
	game->projectile->spec.p_data.dir_x = game->player.dir_x;
	game->projectile->spec.p_data.dir_y = game->player.dir_y;
	game->projectile->state = 1;
}

void	enemy_death(t_game *game, t_entity *enemy, t_list *prev, t_list *cur)
{
	if (prev == NULL)
		game->entity_lst = cur->next;
	else
		prev->next = cur->next;
	free(enemy);
	free(cur);
}

int	projectile_colision(t_game *game)
{
	t_list		*entity_lst;
	t_entity	*entity;
	t_list		*tmp;

	entity_lst = game->entity_lst;
	tmp = NULL;
	while (entity_lst)
	{
		entity = (t_entity *)entity_lst->content;
		if (game->map.arr[(int)game->projectile->pos_y][(int)game->projectile->pos_x] == '1')
			return (1);
		else if (game->map.arr[(int)game->projectile->pos_y][(int)game->projectile->pos_x] == 'D')
		{
			if (find_door((int)game->projectile->pos_x, (int)game->projectile->pos_y, game)->state != OPEN)
				return (1);
		}
		if (entity->type == ENEMY
			&& game->projectile->pos_x >= entity->pos_x - entity->spec.e_data.hit_radius
			&& game->projectile->pos_x <= entity->pos_x + entity->spec.e_data.hit_radius
			&& game->projectile->pos_y >= entity->pos_y - entity->spec.e_data.hit_radius
			&& game->projectile->pos_y <= entity->pos_y + entity->spec.e_data.hit_radius)
		{
			entity->spec.e_data.hp -= 35;
			if (entity->spec.e_data.hp <= 0)
				enemy_death(game, entity, tmp, entity_lst);
			return (1);
		}
		tmp = entity_lst;
		entity_lst = entity_lst->next;
	}
	return (0);
}

void	projectile_update(t_game *game)
{
	if (game->projectile->state == 0)
		return ;
	if (projectile_colision(game))
	{
		game->projectile->state = 0;
		return ;
	}
	game->projectile->pos_x += game->projectile->spec.p_data.dir_x * 0.6;
	game->projectile->pos_y += game->projectile->spec.p_data.dir_y * 0.6;
}
