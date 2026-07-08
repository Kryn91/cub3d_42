#include "enemy_choose_direction.h"

void    change_rigth_direction(t_entity *enemy, double new_x, double new_y, t_game *game)
{
    if (!e_isColiding(new_x, new_y - 1, game))
        change_dir(enemy, 0, -1);
    else if (!e_isColiding(new_x, new_y + 1, game))
        change_dir(enemy, 0, 1);
    else if (!e_isColiding(new_x - 1, new_y, game))
        change_dir(enemy, -1, 0);
}

void    change_left_direction(t_entity *enemy, double new_x, double new_y, t_game *game)
{
    if (!e_isColiding(new_x, new_y + 1, game))
        change_dir(enemy, 0, 1);
    else if (!e_isColiding(new_x, new_y - 1, game))
        change_dir(enemy, 0, -1);
    else if (!e_isColiding(new_x + 1, new_y, game))
        change_dir(enemy, 1, 0);
}

void    change_up_direction(t_entity *enemy, double new_x, double new_y, t_game *game)
{
    if (!e_isColiding(new_x + 1, new_y, game))
        change_dir(enemy, 1, 0);
    else if (!e_isColiding(new_x - 1 , new_y, game))
        change_dir(enemy, -1, 0);
    else if (!e_isColiding(new_x, new_y + 1, game))
        change_dir(enemy, 0, 1);
}

void    change_down_direction(t_entity *enemy, double new_x, double new_y, t_game *game)
{

    if (!e_isColiding(new_x - 1 , new_y, game))
        change_dir(enemy, -1, 0);
    else if (!e_isColiding(new_x + 1, new_y, game))
        change_dir(enemy, 1, 0);
    else if (!e_isColiding(new_x, new_y - 1, game))
        change_dir(enemy, 0, -1);
}

void    choose_direction(t_entity *enemy, t_game *game)
{
    double  new_x;
    double  new_y;

    new_x = enemy->pos_x;
    new_y = enemy->pos_y;
    if (enemy->dir_x == 1 && enemy->dir_y == 0) //droite
       change_rigth_direction(enemy, new_x, new_y, game);
    else if (enemy->dir_x == -1 && enemy->dir_y == 0) //gauche
        change_left_direction(enemy, new_x, new_y, game);
    else if (enemy->dir_x == 0 && enemy->dir_y == -1) //haut
        change_up_direction(enemy, new_x, new_y, game);
    else if (enemy->dir_x == 0 && enemy->dir_y == 1) //bas
        change_down_direction(enemy, new_x, new_y, game);
}