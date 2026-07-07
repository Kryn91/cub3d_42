#include "enemy_patrol.h"
#include "enemy_colision.h"

void    choose_direction(t_entity *enemy, t_game *game)
{
    (void)enemy;
    (void)game;
}
#include <stdio.h>
void    patrol(t_entity *enemy, t_game *game)
{
    double movespeed = 0.10;
    double  new_x;
    double  new_y;
    new_x = enemy->pos_x + enemy->dir_x * movespeed;
    new_y = enemy->pos_y + enemy->dir_y * movespeed;
    printf("ENEMY : x=%f y=%f\n", new_x, new_y);
    if (e_isColiding(new_x, new_y, game) == false)
    {
        printf("is coliding\n");
        enemy->pos_x = new_x;
        enemy->pos_y = new_y;
    }
}