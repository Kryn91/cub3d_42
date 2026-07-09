#ifndef ENEMY_CHOOSE_DIRECTION_H
# define ENEMY_CHOOSE_DIRECTION_H
#include "cub3d.h" 

typedef struct s_vec
{
    double x;
    double y;
} t_vec;

void    choose_direction(t_entity *enemy, t_game *game);
#endif