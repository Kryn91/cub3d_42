#include "enemy_colision.h"

t_door    *e_find_door(int x, int y, t_game *game)
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

bool	e_check_door(double x, double y, t_game *game)
{
	t_door	*door;
	int		new_x;
	int		new_y;

	new_x = (int)x;
	new_y = (int)y;
	if (game->map.arr[new_y][new_x] != 'D')
		return (false);
	door = e_find_door(x, y, game);
	if (!door)
		return (false);
	if (door->state == OPEN)
		return (false);
	return (true);
}

bool	enemy_colision(double x, double y, t_game *game)
{
	if ((int)y < 0 || (int)x < 0)
		return (true);
	if (y >= game->map.height || x >= ft_strlen(game->map.arr[(int)y]))
		return (true);
	if (game->map.arr[(int)y][(int)(x + ENEMY_RADIUS)] == '1')
		return (true);
	if (game->map.arr[(int)y][(int)(x - ENEMY_RADIUS)] == '1')
		return (true);
	if (game->map.arr[(int)(y + ENEMY_RADIUS)][(int)x] == '1')
		return (true);
	if (game->map.arr[(int)(y - ENEMY_RADIUS)][(int)x] == '1')
		return (true);
	return (false);
}

bool	e_isColiding(double x, double y, t_game *game)
{
	if (enemy_colision(x, y, game))
		return (true);
	if (e_check_door(x, y, game))
		return (true);
	return (false);
}
