#include "game_loop.h"
#include "movement.h"
#include "delta_time.h"
#include "door.h"
#include "render.h"
#include "interact.h"
#include "attack.h"
#include "enemy_patrol.h"

void	handle_enemy(t_game *game)
{
	t_list		*tmp;
	t_entity	*enemy;

	tmp = game->entity_lst;
	while (tmp)
	{
		enemy = ((t_entity *)tmp->content);
		if (enemy)
		{
			if (enemy->estate == PATROL)
				patrol(enemy, game);
		}
		tmp = tmp->next;
	}
}

int	game_loop(t_game *game)
{
	double  now;

	now  = get_time();
	if (now - game->fps.last_frame < 1.0 / 60.0)
		return (0);
	game->fps.last_frame = now;
	set_delta_time(game);
	move_player(game);
	handle_enemy(game);
	projectile_update(game);
	interact(game);
	handle_door(game);
	render(game);
	return (0);
}
