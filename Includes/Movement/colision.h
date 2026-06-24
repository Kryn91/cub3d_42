#ifndef COLISION_H
# define COLISION_H

# include "cub3d.h"
# define PLAYER_RADIUS 0.15

bool	isColiding(double x, double y, t_game *game);
t_door    *find_door(int x, int y, t_game *game);
#endif