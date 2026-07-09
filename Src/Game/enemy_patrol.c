#include "enemy_patrol.h"
#include "enemy_colision.h"
#include "enemy_choose_direction.h"

void    change_dir(t_entity *enemy, double x, double y)
{
    enemy->dir_x = x;
    enemy->dir_y = y;
}

void    patrol(t_entity *enemy, t_game *game)
{
    double movespeed = 0.06;
    double  new_x;
    double  new_y;
    new_x = enemy->pos_x + enemy->dir_x * movespeed;
    new_y = enemy->pos_y + enemy->dir_y * movespeed;
    if (e_isColiding(new_x, new_y, game) == false)
    {
        if (!e_isColiding(new_x, enemy->pos_y, game))
            enemy->pos_x = new_x;
        if (!e_isColiding(enemy->pos_x, new_y, game))
            enemy->pos_y = new_y;
    }
    else if (e_isColiding(new_x, new_y, game))
        choose_direction(enemy, game);
}
