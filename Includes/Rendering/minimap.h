/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:43:58 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:43:58 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define MINIMAP_SIZE 200
# define MINIMAP_TILE_SIZE 30
# define MINIMAP_POS_X 20
# define MINIMAP_POS_Y 20

typedef struct s_minimap_pixel
{
	int		x;
	int		y;
	double	map_x;
	double	map_y;
}			t_minimap_pixel;

#endif
