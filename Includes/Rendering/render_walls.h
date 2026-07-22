/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:44:28 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:44:31 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_WALLS_H
# define RENDER_WALLS_H

# include "cub3d.h"
# include "raycasting.h"

void	render_door(t_game *game, t_ray *ray, t_img *image, int x);
void	render_walls(t_game *game, t_ray *ray, int x, t_img *image);

#endif
