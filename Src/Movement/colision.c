#include "colision.h"

t_door    *find_door(int x, int y, t_game *game)
{
    t_door *tmp;

    tmp = game->door;
    while (tmp)
    {
        if (tmp->x == x && tmp->y == y)
				return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}
bool	check_wall_radius(double x, double y, t_game *game)
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

bool	check_door(double x, double y, t_game *game)
{
	t_door	*door;
	int		new_x;
	int		new_y;

	new_x = (int)x;
	new_y = (int)y;
	if (game->map.arr[new_y][new_x] != 'D')
		return false;
	door = find_door(x, y, game);
	if (!door)
		return false;
	if (door->state == OPEN)
		return (false);
	return(true);
}

bool	isColiding(double x, double y, t_game *game)
{
	if (check_wall_radius(x, y, game))
		return (true);
	if(check_door(x, y, game))
		return (true);
	return (false);
}
