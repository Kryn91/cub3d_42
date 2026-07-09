#include <stdlib.h>
#include "enemy_choose_direction.h"
#include "enemy_colision.h"

void choose_direction(t_entity *enemy, t_game *game)
{
    int i;

    i = rand() % 8;
    t_vec dirs[8] =
    {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
        {1, 1},
        {-1, 1},
        {1, -1},
        {-1, -1}
    };
    while (i < 8)
    {
        if (!e_isColiding(enemy->pos_x + dirs[i].x, enemy->pos_y + dirs[i].y, game))
        {
            enemy->dir_x = dirs[i].x;
            enemy->dir_y = dirs[i].y;
            return;
        }
        i++;
    }
}
