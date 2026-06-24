#include "cub3d.h"
#include "movement.h"
#include "colision.h"

void	move_forward(t_game *game, double movespeed)
{
	double	new_x;
	double	new_y;
	
	new_x = game->player.pos_x + game->player.dir_x * movespeed;
	new_y = game->player.pos_y + game->player.dir_y * movespeed;
	if (!isColiding(new_x, game->player.pos_y, game) &&
		!isDoor(new_x, game->player.pos_y, game))
		game->player.pos_x += game->player.dir_x * movespeed;
	if (!isColiding(game->player.pos_x, new_y, game)
	 && !isDoor(game->player.pos_x, new_y, game))
		game->player.pos_y += game->player.dir_y * movespeed;
	if (isDoor(new_x, game->player.pos_y, game) && Door_is_open(new_x, game->player.pos_y, game))
		game->player.pos_x += game->player.dir_x * movespeed;
	if (isDoor(game->player.pos_x, new_y, game) && Door_is_open(new_x, game->player.pos_y, game))
		game->player.pos_y += game->player.dir_y * movespeed;

}

void	move_player_back(t_game *game, double movespeed)
{
	double	new_x;
	double	new_y;
	
	new_x = game->player.pos_x - game->player.dir_x * movespeed;
	new_y = game->player.pos_y - game->player.dir_y * movespeed;
	if (!isColiding(new_x, game->player.pos_y, game))	
		game->player.pos_x -= game->player.dir_x * movespeed;
	if (!isColiding(game->player.pos_x, new_y, game))
		game->player.pos_y -= game->player.dir_y * movespeed;
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