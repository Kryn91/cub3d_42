/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:44 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:46:45 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity_sort.h"

void	swap_entities(t_entity *entity1, t_entity *entity2, t_list *cur)
{
	void	*tmp;

	tmp = entity1;
	cur->content = entity2;
	cur->next->content = tmp;
}

void	sort_entities(t_list **entity_lst)
{
	int			swap;
	t_list		*cur;
	t_entity	*entity1;
	t_entity	*entity2;

	swap = 1;
	if (!*entity_lst)
		return ;
	while (swap)
	{
		cur = *entity_lst;
		swap = 0;
		while (cur->next)
		{
			entity1 = (t_entity *)cur->content;
			entity2 = (t_entity *)cur->next->content;
			if (entity1->transform_y < entity2->transform_y)
			{
				swap_entities(entity1, entity2, cur);
				swap = 1;
			}
			cur = cur->next;
		}
	}
}
