#include "bool.h"
#include "cub3d.h"
#include "movement.h"
#include "handle_input.h"

bool	isColiding(double pos_x, double pos_y, t_game *game)
{
	int	posx;
	int	posy;

	posx = (int)pos_x;
	posy = (int)pos_y;
	if (game->map.arr[posy][posx] == '1')
		return (true);
	return (false);
}

void	move_walk(int keycode, double movespeed, t_game *game)
{
	if (keycode == KEY_W && !isColiding(game->player.pos_x + game->player.dir_x
			* movespeed, game->player.pos_y + game->player.dir_y * movespeed,
			game))
	{
		game->player.pos_x += game->player.dir_x * movespeed;
		game->player.pos_y += game->player.dir_y * movespeed;
	}
	else if (keycode == KEY_S && !isColiding(game->player.pos_x
			- game->player.dir_x * movespeed, game->player.pos_y
			- game->player.dir_y * movespeed, game))
	{
		game->player.pos_x -= game->player.dir_x * movespeed;
		game->player.pos_y -= game->player.dir_y * movespeed;
	}
}

void	move_strafe(int keycode, double movespeed, t_game *game)
{
	if (keycode == KEY_D && !isColiding(game->player.pos_x
			+ game->player.plane_x * movespeed, game->player.pos_y
			+ game->player.plane_y * movespeed, game))
	{
		game->player.pos_x += game->player.plane_x * movespeed;
		game->player.pos_y += game->player.plane_y * movespeed;
	}
	else if (keycode == KEY_A && !isColiding(game->player.pos_x
			- game->player.plane_x * movespeed, game->player.pos_y
			- game->player.plane_y * movespeed, game))
	{
		game->player.pos_y -= game->player.plane_y * movespeed;
		game->player.pos_x -= game->player.plane_x * movespeed;
	}
}