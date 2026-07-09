#ifndef ENEMY_PATROL_H
# define ENEMY_PATROL_H
# include "entity.h"

void    patrol(t_entity *enemy, t_game *game);
void    change_dir(t_entity *enemy, double x, double y);

#endif
