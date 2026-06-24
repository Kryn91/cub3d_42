#include "colision.h"

bool    isDoor(double x, int y, t_game *game)
{
	if (game->map.arr[(int)y][(int)(x + PLAYER_RADIUS)] == 'D')
		return (true);
	if (game->map.arr[(int)y][(int)(x - PLAYER_RADIUS)] == 'D')
		return (true);
	if (game->map.arr[(int)(y + PLAYER_RADIUS)][(int)x] == 'D')
		return (true);
	if (game->map.arr[(int)(y - PLAYER_RADIUS)][(int)x] == 'D')
		return (true);
    return (false);
}

bool    Door_is_open(double x, int y, t_game *game)
{
    t_door *tmp;

    if (!game->door)
        return (1);
    tmp = game->door;
    while (tmp)
    {
        if (tmp->x == x && tmp->y == y)
        {
            if (tmp->state == OPEN)
                return (true);
        }
        tmp = tmp->next;
    }
    return (false);
}

bool	isColiding(double x, double y, t_game *game)
{
	if (game->map.arr[(int)y][(int)(x + PLAYER_RADIUS)] == '1')
		return (true);
	if (game->map.arr[(int)y][(int)(x - PLAYER_RADIUS)] == '1')
		return (true);
	if (game->map.arr[(int)(y + PLAYER_RADIUS)][(int)x] == '1')
		return (true);
	if (game->map.arr[(int)(y - PLAYER_RADIUS)][(int)x] == '1')
		return (true);
	return (false);
}
