/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_chase_player.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:27:20 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:33:25 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CHASE_PLAYER_H
# define ENEMY_CHASE_PLAYER_H

# include "cub3d.h"

void	chase_player(t_game *game, t_entity *enemy);
t_bool	is_in_range(t_game *game, t_entity *enemy);

#endif
