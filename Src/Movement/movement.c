/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:17 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:57:48 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colision.h"
#include "cub3d.h"
#include "movement.h"

void	move_forward(t_game *game, double movespeed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * movespeed;
	new_y = game->player.pos_y + game->player.dir_y * movespeed;
	if (!iscoliding(new_x, game->player.pos_y, game))
		game->player.pos_x += game->player.dir_x * movespeed;
	if (!iscoliding(game->player.pos_x, new_y, game))
		game->player.pos_y += game->player.dir_y * movespeed;
}

void	move_player_back(t_game *game, double movespeed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * movespeed;
	new_y = game->player.pos_y - game->player.dir_y * movespeed;
	if (!iscoliding(new_x, game->player.pos_y, game))
		game->player.pos_x -= game->player.dir_x * movespeed;
	if (!iscoliding(game->player.pos_x, new_y, game))
		game->player.pos_y -= game->player.dir_y * movespeed;
}

void	move_right(t_game *game, double movespeed)
{
	if (!iscoliding(game->player.pos_x + game->player.plane_x * movespeed,
			game->player.pos_y + game->player.plane_y * movespeed, game))
	{
		game->player.pos_x += game->player.plane_x * movespeed;
		game->player.pos_y += game->player.plane_y * movespeed;
	}
}

void	move_left(t_game *game, double movespeed)
{
	if (!iscoliding(game->player.pos_x - game->player.plane_x * movespeed,
			game->player.pos_y - game->player.plane_y * movespeed, game))
	{
		game->player.pos_y -= game->player.plane_y * movespeed;
		game->player.pos_x -= game->player.plane_x * movespeed;
	}
}

void	move_player(t_game *game)
{
	double	movespeed;

	movespeed = 0.10;
	if (game->input.a)
		move_left(game, movespeed);
	if (game->input.d)
		move_right(game, movespeed);
	if (game->input.w)
		move_forward(game, movespeed);
	if (game->input.s)
		move_player_back(game, movespeed);
}
