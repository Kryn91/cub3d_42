/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:29:08 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:29:08 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_PATROL_H
# define ENEMY_PATROL_H
# include "entity.h"

void	patrol(t_entity *enemy, t_game *game);
void	change_dir(t_entity *enemy, double x, double y);

#endif
