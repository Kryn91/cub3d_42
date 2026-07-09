#ifndef ENEMY_CHASE_PLAYER_H
# define ENEMY_CHASE_PLAYER_H
# include "cub3d.h"

void    chase_player(t_game *game, t_entity *enemy);
bool    is_in_range(t_game *game, t_entity *enemy);
#endif