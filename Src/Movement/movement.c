#include "bool.h"
#include "cub3d.h"
#include "movement.h"

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

void	move_forward(t_game *game, double movespeed)
{
	if (!isColiding(game->player.pos_x + game->player.dir_x
			* movespeed, game->player.pos_y + game->player.dir_y * movespeed,
			game))	
	{
		game->player.pos_x += game->player.dir_x * movespeed;
		game->player.pos_y += game->player.dir_y * movespeed;
	}
}

void	move_player_back(t_game *game, double movespeed)
{

	if (!isColiding(game->player.pos_x
			- game->player.dir_x * movespeed, game->player.pos_y
			- game->player.dir_y * movespeed, game))
	{
		game->player.pos_x -= game->player.dir_x * movespeed;
		game->player.pos_y -= game->player.dir_y * movespeed;
	}
}

void	move_right(t_game *game, double movespeed)
{
	if (!isColiding(game->player.pos_x
			+ game->player.plane_x * movespeed, game->player.pos_y
			+ game->player.plane_y * movespeed, game))
	{
		game->player.pos_x += game->player.plane_x * movespeed;
		game->player.pos_y += game->player.plane_y * movespeed;
	}

}

void	move_left(t_game *game, double movespeed)
{
	if (!isColiding(game->player.pos_x
			- game->player.plane_x * movespeed, game->player.pos_y
			- game->player.plane_y * movespeed, game))
	{
		game->player.pos_y -= game->player.plane_y * movespeed;
		game->player.pos_x -= game->player.plane_x * movespeed;
	}
}

void	move_player(t_game *game)
{
	double	movespeed;

	movespeed = 0.10;
	if (game->input.A)
		move_left(game, movespeed);
	if (game->input.D)
		move_right(game, movespeed);
	if (game->input.W)
		move_forward(game, movespeed);
	if (game->input.S)
		move_player_back(game, movespeed);
}