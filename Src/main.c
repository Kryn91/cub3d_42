#include "libft.h"
#include "cub3d.h"
#include "handle_input.h"
#include "free_memory.h"
#include "free_list.h"
#include "mlx.h"
#include "init_player.h"
#include "checker.h"
#include "game_loop.h"
#include "init_door.h"
#include "attack.h"

int		render(t_game *game);
void	init(t_game *game);

int	run_game(t_game *game)
{
	game->mlx = mlx_init();
	init(game);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
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

int		main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_memset(game, 0, sizeof(t_game));
	parsing(ac, av, game);
	init_player(game);
	game->fps.cap = 60;
	checker(game);
	init_door(game);
	if (run_game(game) != 0)
		return (1);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(game);
	free_door(game->door);
	free_texture(game);
	free(game);
	return (0);
}
