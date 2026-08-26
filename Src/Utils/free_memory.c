/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:47:28 by apeterso          #+#    #+#             */
/*   Updated: 2026/08/26 16:35:54 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_list.h"
#include "free_memory.h"
#include "mlx.h"

void	free_tab(size_t size, char **tab)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
}

void	free_array(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_split(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_texture(t_game *game)
{
	if (game->map.walls[0].img.img_ptr)
	{
		mlx_destroy_image(game->mlx, game->map.walls[0].img.img_ptr);
		game->map.walls[0].img.img_ptr = NULL;
	}
	if (game->map.walls[1].img.img_ptr)
	{
		mlx_destroy_image(game->mlx, game->map.walls[1].img.img_ptr);
		game->map.walls[1].img.img_ptr = NULL;
	}
	if (game->map.walls[2].img.img_ptr)
	{
		mlx_destroy_image(game->mlx, game->map.walls[2].img.img_ptr);
		game->map.walls[2].img.img_ptr = NULL;
	}
	if (game->map.walls[3].img.img_ptr)
	{
		mlx_destroy_image(game->mlx, game->map.walls[3].img.img_ptr);
		game->map.walls[3].img.img_ptr = NULL;
	}
	if (game->door_texture.img.img_ptr)
	{
		mlx_destroy_image(game->mlx, game->door_texture.img.img_ptr);
		game->door_texture.img.img_ptr = NULL;
	}
	if (game->game_over_tex.img.img_ptr)
	{
		mlx_destroy_image(game->mlx, game->game_over_tex.img.img_ptr);
		game->game_over_tex.img.img_ptr = NULL;
	}
	destroy_entity_images(game);
	if (game->hand.tex[0].img.img_ptr)
	{
		mlx_destroy_image(game->mlx, game->hand.tex[0].img.img_ptr);
		game->hand.tex[0].img.img_ptr = NULL;
	}
	if (game->hand.tex[1].img.img_ptr)
	{
		mlx_destroy_image(game->mlx, game->hand.tex[1].img.img_ptr);
		game->hand.tex[1].img.img_ptr = NULL;
	}
	if (game->spell.tex[0].img.img_ptr)
	{
		mlx_destroy_image(game->mlx, game->spell.tex[0].img.img_ptr);
		game->spell.tex[0].img.img_ptr = NULL;
	}
	if (game->spell.tex[1].img.img_ptr)
	{
		mlx_destroy_image(game->mlx, game->spell.tex[1].img.img_ptr);
		game->spell.tex[1].img.img_ptr = NULL;
	}
	if (game->spell.tex[2].img.img_ptr)
	{
		mlx_destroy_image(game->mlx, game->spell.tex[2].img.img_ptr);
		game->spell.tex[2].img.img_ptr = NULL;
	}

}

void	free_map(t_game *game)
{
	if (game->map.arr)
		free_array(game->map.arr);
	if (game->map.walls[0].path)
	{
		free(game->map.walls[0].path);
		game->map.walls[0].path = NULL;
	}
	if (game->map.walls[1].path)
	{
		free(game->map.walls[1].path);
		game->map.walls[1].path = NULL;
	}
	if (game->map.walls[2].path)
	{
		free(game->map.walls[2].path);
		game->map.walls[2].path = NULL;
	}
	if (game->map.walls[3].path)
	{
		free(game->map.walls[3].path);
		game->map.walls[3].path = NULL;
	}
	if (game->map.ceiling_parse)
	{
		free(game->map.ceiling_parse);
		game->map.ceiling_parse = NULL;
	}
	if (game->map.floor_parse)
	{
		free(game->map.floor_parse);
		game->map.floor_parse = NULL;
	}
}
