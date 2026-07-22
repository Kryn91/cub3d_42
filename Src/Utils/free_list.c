/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:47:24 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:47:25 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_list.h"
#include "mlx.h"
#include <stdlib.h>

void	free_door(t_door *door)
{
	t_door	*tmp;
	t_door	*next;

	tmp = door;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void	free_entity(void *content)
{
	free(content);
}

void	destroy_entity_images(t_game *game)
{
	t_list		*tmp;
	t_entity	*entity;
	int			i;

	tmp = game->entity_lst;
	while (tmp)
	{
		entity = (t_entity *)tmp->content;
		if (entity)
		{
			i = 0;
			while (i < 3)
			{
				if (entity->tex[i].img.img_ptr)
					mlx_destroy_image(game->mlx, entity->tex[i].img.img_ptr);
				i++;
			}
		}
		tmp = tmp->next;
	}
}
