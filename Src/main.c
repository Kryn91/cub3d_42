/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:47:10 by apeterso          #+#    #+#             */
/*   Updated: 2026/08/19 17:53:32 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "attack.h"
#include "checker.h"
#include "cub3d.h"
#include "free_list.h"
#include "free_memory.h"
#include "game_loop.h"
#include "handle_input.h"
#include "init_door.h"
#include "init_enemy.h"
#include "init_player.h"
#include "init_texture.h"
#include "libft.h"
#include "mlx.h"

int		render(t_game *game);

int	run_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nMLX initialization failed\n", 2);
		free_map(game);
		return (1);
	}
	init_texture(game);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!game->win)
	{
		ft_putstr_fd("Error\nWindow initialization failed\n", 2);
		free_map(game);
		return (1);
	}
	mlx_hook(game->win, 17, 0, (void *)close_win, game);
	mlx_hook(game->win, 2, 1L << 0, (void *)key_press, game);
	mlx_hook(game->win, 3, 1L << 1, (void *)key_release, game);
	mlx_mouse_hide(game->mlx, game->win);
	mlx_hook(game->win, 6, 1L << 6, (void *)handle_mouse_input, game);
	mlx_mouse_hook(game->win, (void *)handle_mouse, game);
	mlx_loop_hook(game->mlx, (void *)game_loop, game);
	mlx_loop(game->mlx);
	return (0);
}

void	init_game_data(t_game *game)
{
	game->first_loop = 1;
	game->fps.cap = 60;
	game->hand.frame = 0;
	game->spell.frame = 0;
	game->spell.last_frame_time = 0;
	game->last_shoot_time = -100;
	game->hand.prepared = 0;
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_memset(game, 0, sizeof(t_game));
	parsing(ac, av, game);
	init_player(game);
	init_game_data(game);
	checker(game);
	init_door(game);
	init_enemy(game);
	if (run_game(game) != 0)
		return (1);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_lstclear(&game->entity_lst, free_entity);
	free_map(game);
	free_door(game->door);
	free_texture(game);
	free(game);
	return (0);
}
