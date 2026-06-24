#ifndef COLISION_H
# define COLISION_H

# include "cub3d.h"
# define PLAYER_RADIUS 0.15

bool    isDoor(double x, int y, t_game *game);
bool	isColiding(double x, double y, t_game *game);
bool    Door_is_open(double x, int y, t_game *game);
#endif