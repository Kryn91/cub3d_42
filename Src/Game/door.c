#include "door.h"

void    open_door(t_game *game)
{
    t_door *tmp;

    tmp = game->door;
    while (tmp)
    {
        if (tmp->state == PROGRESS)
        {
            if (tmp->progress < 1)
                tmp->progress += 0.10;
            if (tmp->progress == 1)
                tmp->state = OPEN;
        }
        tmp = tmp->next; 
    }
}

void    handle_door(t_game *game)
{
    open_door(game);
}