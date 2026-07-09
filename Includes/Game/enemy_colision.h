#ifndef ENEMY_COLISION_H
# define ENEMY_COLISION_H
# include "cub3d.h"

bool	e_isColiding(double x, double y, t_game *game);
bool	e_check_door(double x, double y, t_game *game);
#endif