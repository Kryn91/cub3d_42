/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:20:14 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:20:15 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_FILE_H
# define READ_MAP_FILE_H
# include "cub3d.h"

int		open_file(char *map);
void	parse_map(char *map, t_game *game);

#endif
