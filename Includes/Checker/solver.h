#ifndef SOLVER_H
# define SOLVER_H
# include "cub3d.h"

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

void    stack_init(t_stack *stack, int capacity);
void    stack_push(t_stack *stack, int pos_x, int pos_y);
t_point stack_pop(t_stack *stack);
int     stack_empty(t_stack *stack);
#endif