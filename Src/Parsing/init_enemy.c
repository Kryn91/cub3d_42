/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <kealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:25 by apeterso          #+#    #+#             */
/*   Updated: 2026/08/28 17:08:39 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "delta_time.h"
#include "entity.h"
#include "free_game.h"
#include "free_list.h"
#include "free_memory.h"
#include "init_enemy.h"
#include "libft.h"

t_entity	*create_entity(int x, int y)
{
	t_entity	*content;

	content = malloc(sizeof(t_entity));
	if (!content)
		return (NULL);
	content = ft_memset(content, 0, sizeof(t_entity));
	if (!content)
		return (free(content), NULL);
	content->type = ENEMY;
	content->state = 1;
	content->pos_x = x + 0.5;
	content->pos_y = y + 0.5;
	content->dir_x = -1;
	content->dir_y = 0;
	content->estate = PATROL;
	content->spec.e_data.hp = 100;
	content->spec.e_data.hit_radius = 0.5;
	content->frame = 0;
	content->last_frame_time = get_time();
	return (content);
}

int	enemy_add_back(int y, int x, t_list **enemy)
{
	t_list		*tmp;
	t_list		*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (1);
	new->content = create_entity(x, y);
	if (!new->content)
		return (free(new), 1);
	new->next = NULL;
	if (!*enemy)
	{
		*enemy = new;
		return (0);
	}
	tmp = *enemy;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

int	create_enemy(char **map, t_list **enemy)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'O')
			{
				if (enemy_add_back(y, x, enemy) == 1)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	init_enemy(t_game *game)
{
	t_list	*enemy;
	int		state;

	enemy = NULL;
	state = create_enemy(game->map.arr, &enemy);
	game->entity_lst = enemy;
	if (state == 1)
	{
		ft_putstr_fd("Error\nAllocating memory malloc fail\n", 2);
		free_game(game);
		exit(1);
	}
}
