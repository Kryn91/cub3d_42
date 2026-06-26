#include "interact.h"
#include "colision.h"
#include <stdio.h>

void interact(t_game *game)
{
    int x = (int)(game->player.pos_x + game->player.dir_x);
    int y = (int)(game->player.pos_y + game->player.dir_y);
    t_door *door;
    if (!game->input.E)
        return;

    if (game->map.arr[y][x] != 'D')
        return;

    door = find_door(x, y, game);
    if (!door)
        return;
    if (door->state == CLOSE)
    {
        door->state = PROGRESS;
    }
    if (door->state == OPEN)
    {
        door->state = CLOSING;
    }
}
