/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:15 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:53:48 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_input.h"
#include "key.h"

void	handle_arrow(int keycode, t_game *game)
{
	if (keycode == KEY_RIGHT)
		rotate_player(game, 0.10);
	if (keycode == KEY_LEFT)
		rotate_player(game, -0.10);
}

void	key_press(int keycode, t_game *game)
{
	handle_arrow(keycode, game);
	if (keycode == KEY_A)
		game->input.a = TRUE;
	if (keycode == KEY_D)
		game->input.d = TRUE;
	if (keycode == KEY_S)
		game->input.s = TRUE;
	if (keycode == KEY_W)
		game->input.w = TRUE;
	if (keycode == KEY_E)
		game->input.e = TRUE;
	else if (keycode == KEY_ESC)
		close_win(game);
}

void	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->input.a = FALSE;
	if (keycode == KEY_D)
		game->input.d = FALSE;
	if (keycode == KEY_S)
		game->input.s = FALSE;
	if (keycode == KEY_W)
		game->input.w = FALSE;
	if (keycode == KEY_E)
		game->input.e = FALSE;
}
