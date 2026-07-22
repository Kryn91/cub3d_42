/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_colision.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:27:47 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:58:25 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_COLISION_H
# define ENEMY_COLISION_H
# include "cub3d.h"

t_bool	e_iscoliding(double x, double y, t_game *game);
t_bool	e_check_door(double x, double y, t_game *game);

#endif
