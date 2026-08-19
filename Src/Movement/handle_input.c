/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:10 by apeterso          #+#    #+#             */
/*   Updated: 2026/08/19 17:58:20 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_list.h"
#include "free_memory.h"
#include "handle_input.h"
#include "init_texture.h"
#include "key.h"
#include "libft.h"
#include "mlx.h"
#include "movement.h"
#include "render.h"
#include "stdlib.h"
#include "vector_manipulation.h"
#include <math.h>

void	close_win(t_game *game)
{
	free_texture(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_lstclear(&game->entity_lst, free_entity);
	free_map(game);
	free_door(game->door);
	free(game->mlx);
	free(game);
	exit(0);
}

void	rotate_player(t_game *game, double angle)
{
	double	old_x;
	double	old_y;
	double	old_plane_x;
	double	old_plane_y;

	old_x = game->player.dir_x;
	old_y = game->player.dir_y;
	game->player.dir_x = (old_x * cos(angle)) - (old_y * sin(angle));
	game->player.dir_y = (old_x * sin(angle)) + (old_y * cos(angle));
	old_plane_x = game->player.plane_x;
	old_plane_y = game->player.plane_y;
	game->player.plane_x = (old_plane_x * cos(angle)) - (old_plane_y
			* sin(angle));
	game->player.plane_y = (old_plane_x * sin(angle)) + (old_plane_y
			* cos(angle));
	game->player.rotation_angle += angle;
}

void	handle_mouse_input(int x, int y, t_game *game)
{
	int	center_x;
	int	center_y;
	int	delta;

	center_x = SCREEN_WIDTH / 2;
	center_y = SCREEN_HEIGHT / 2;
	delta = x - game->player.mouse_x;
	game->player.mouse_x = x;
	if (game->first_loop)
	{
		game->first_loop = 0;
		return ;
	}
	if (x == center_x && y == center_y)
		return ;
	rotate_player(game, delta * MOUSE_SENSIBILITY);
	mlx_mouse_move(game->mlx, game->win, center_x, center_y);
}
