#include "libft.h"
#include "cub3d.h"
#include "handle_input.h"
#include "free_memory.h"
#include "mlx.h"
#include "init_player.h"
#include "checker.h"

int		render(t_game *game);
void	init(t_game *game);

int	run_game(t_game *game)
{
	game->mlx = mlx_init();
	init(game);
	game->win = mlx_new_window(game->mlx, game->screen_x, game->screen_y, "cub3d");
	mlx_loop_hook(game->mlx, (void *)render, game);
	mlx_hook(game->win,  17, 0, (void *)close_win, game);
	mlx_hook(game->win, 2, 1L << 0, (void *)handle_input, game);
	mlx_hook(game->win, 6 , 1L << 6, (void *)handle_mouse_input, game);
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
	checker(game);
	//checkeur, test les erreurs et ramene dans le main
	if (run_game(game) != 0)
		return (1);
	free_map(game);
	free(game);
	return (0);
}
