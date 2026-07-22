/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:54:18 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:54:18 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_LIST_H
# define FREE_LIST_H
# include "cub3d.h"

void	free_door(t_door *door);
void	free_entity(void *content);
void	destroy_entity_images(t_game *game);

#endif
