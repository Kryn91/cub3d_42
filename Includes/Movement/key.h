/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:36:05 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:36:07 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "cub3d.h"

void	handle_arrow(int keycode, t_game *game);
void	key_press(int keycode, t_game *game);
void	key_release(int keycode, t_game *game);
void	rotate_player(t_game *game, double angle);

#endif
