#include "door.h"
#include "cub3d.h"

#include "stdio.h"

void    open_door(t_game *game)
{
    t_door *tmp;

    tmp = game->door;
    while (tmp)
    {
        if (tmp->state == PROGRESS)
        {
            if (tmp->progress > 0)
                tmp->progress -= 0.03;
            // printf("Progress state: %f\n", tmp->progress);
            if (tmp->progress < 0.05)
                tmp->state = OPEN;
        }
        if (tmp->state == CLOSING)
        {
            if (tmp->progress < 1)
                tmp->progress += 0.03;
            if (tmp->progress == 1)
                tmp->state = CLOSE;
        }
        tmp = tmp->next;
    }
}

void    handle_door(t_game *game)
{
    open_door(game);
}
