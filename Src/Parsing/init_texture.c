/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:30 by apeterso          #+#    #+#             */
/*   Updated: 2026/08/26 18:02:21 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boolean.h"
#include "entity.h"
#include "free_game.h"
#include "free_list.h"
#include "free_memory.h"
#include "init_texture.h"
#include "mlx.h"
#include <stdio.h>

void	init_tex(t_game *game, t_texture *tex, char *path)
{
	tex->path = path;
	tex->img.img_ptr = mlx_xpm_file_to_image(game->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img.img_ptr)
	{
		free_game(game);
		printf("Error\nFailed to initialize texture\n");
		exit(1);
	}
	tex->img.addr = mlx_get_data_addr(tex->img.img_ptr, &tex->img.bpp,
			&tex->img.size_line, &tex->img.endian);
}

t_bool	init_enemy_tex(t_game *game, t_list *enemy)
{
	t_list		*temp;
	t_entity	*entity;

	temp = enemy;
	while (temp)
	{
		entity = ((t_entity *)temp->content);
		if (entity)
		{
			init_tex(game, &entity->tex[0], "Assets/Entity/Enemy.xpm");
			temp->content = entity;
		}
		temp = temp->next;
	}
	return (TRUE);
}

void	init_texture(t_game *game)
{
	init_tex(game, game->map.walls, game->map.walls[0].path);
	init_tex(game, game->map.walls + 1, game->map.walls[1].path);
	init_tex(game, game->map.walls + 2, game->map.walls[2].path);
	init_tex(game, game->map.walls + 3, game->map.walls[3].path);
	init_tex(game, game->hand.tex, "Assets/Hand/backhand.xpm");
	init_tex(game, game->hand.tex + 1, "Assets/Hand/fronthand.xpm");
	init_tex(game, game->spell.tex, "Assets/Spell/Flame0.xpm");
	init_tex(game, game->spell.tex + 1, "Assets/Spell/Flame1.xpm");
	init_tex(game, game->spell.tex + 2, "Assets/Spell/Flame2.xpm");
	init_enemy_tex(game, game->entity_lst);
	init_tex(game, &game->door_texture, "Assets/Wall/door.xpm");
}
