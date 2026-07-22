/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solver.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:21:09 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 16:00:12 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_SOLVER_H
# define MAP_SOLVER_H

# include "cub3d.h"

typedef struct s_start
{
	int	x;
	int	y;
}		t_start;

t_bool	map_solver(t_game *game);

#endif
