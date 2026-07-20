#include "game_loop.h"
#include "bool.h"
#include "entity.h"
#include "handle_input.h"
#include "movement.h"
#include "door.h"
#include "render.h"
#include "interact.h"
#include "attack.h"
#include "enemy_patrol.h"
#include "enemy_detect_player.h"
#include "enemy_chase_player.h"
#include "enemy_attack_player.h"
#include "init_texture.h"
#include "mlx.h"

void	handle_state(t_game *game, t_entity *enemy)
{
	bool			detected;
	enum e_enemy_state	old_state;

	old_state = enemy->estate;
	detected = detect_player(game, enemy);
	if (detected == true)
	{
		if (is_in_range(game, enemy) == false)
		{
				enemy->estate = CHASE;
				chase_player(game, enemy);
		}
		else
			attack_player(game, enemy);
	}
	else
		enemy->estate = PATROL;
	if (old_state != PATROL && enemy->estate == PATROL)
    {
        enemy->dir_x = -enemy->dir_x;
        enemy->dir_y = -enemy->dir_y;
    }
	if (enemy->estate == PATROL)
		patrol(enemy, game);
}

void	handle_enemy(t_game *game)
{
	t_list		*tmp;
	t_entity	*enemy;
	tmp = game->entity_lst;
	while (tmp)
	{
		enemy = ((t_entity *)tmp->content);
		if (enemy)
			handle_state(game, enemy);
		tmp = tmp->next;
	}
}

#include <stdio.h>

int	game_loop(t_game *game)
{
	t_vec	pos;

	pos.x =0;
	pos.y = 0;
	if (game->player.is_dead == true)
	{
		init_tex(game, &game->game_over_tex, "Assets/game_over.xpm");
		sprite_to_img(&game->game_over_tex, &game->game_over_tex.img, pos, 1);
		mlx_put_image_to_window(game->mlx, game->win, game->game_over_tex.img.img_ptr, 0, 0);
		return (0);
	}
	if (game->player.hp <= 0)
		game->player.is_dead = true;
	move_player(game);
	handle_enemy(game);
	// printf("%c\n", game->map.arr[0][1]);
	projectile_update(game);
	interact(game);
	handle_door(game);
	render(game);
	return (0);
}
