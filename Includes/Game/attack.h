/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:21:34 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:26:48 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATTACK_H
# define ATTACK_H

# include "cub3d.h"

void	shoot(t_game *game);
void	projectile_update(t_game *game);
void	handle_mouse(int button, int x, int y, void *param);

#endif
