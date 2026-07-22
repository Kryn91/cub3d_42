#ifndef COLISION_H
# define COLISION_H

# include "cub3d.h"
# define PLAYER_RADIUS 0.15

typedef enum e_collision
{
	COL_NONE,
	COL_WALL,
	COL_ENEMY
}	t_col;

bool	isColiding(double x, double y, t_game *game);
t_door	*find_door(int x, int y, t_game *game);
bool	check_wall_radius(double x, double y, t_game *game);

#endif
