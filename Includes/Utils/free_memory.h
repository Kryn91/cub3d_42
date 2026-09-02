/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:54:30 by apeterso          #+#    #+#             */
/*   Updated: 2026/09/02 13:08:44 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_MEMORY_H
# define FREE_MEMORY_H

# include "cub3d.h"
# include "stdlib.h"

void	free_tab(size_t size, char **tab);
void	free_array(char **arr);
void	free_map(t_game *game);
void	free_split(char **str);

#endif
