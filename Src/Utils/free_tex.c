/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 13:15:05 by apeterso          #+#    #+#             */
/*   Updated: 2026/09/02 13:15:06 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "free_tex.h"
#include "free_list.h"
#include "mlx.h"

void	free_walls_tex(t_game *game)
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
}

void	free_hand_tex(t_game *game)
{
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
}

void	free_spell_tex(t_game *game)
{
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

void	free_texture(t_game *game)
{
	free_walls_tex(game);
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
	free_hand_tex(game);
	free_spell_tex(game);
}
