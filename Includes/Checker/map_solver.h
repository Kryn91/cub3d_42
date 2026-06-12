#ifndef MAP_SOLVER_H
# define MAP_SOLVER_H
#include "cub3d.h"

typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct  s_stack
{
    t_point *data;
    int size;
    int capacity;
}   t_stack;
void    solver(t_map *map);
#endif