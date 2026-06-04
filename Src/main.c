#include "libft.h"
#include "cub3d.h"
#include "handle_input.h"
#include "mlx.h"

int		ray(t_game *game);
void	init_test(t_game *game, int idx);

int	run_game(t_game *game)
{
	int	idx;

	idx = 3;
	game->mlx = mlx_init();
	init_test(game, idx);
	game->win = mlx_new_window(game->mlx, game->screen_x, game->screen_y, "cub3d");
	mlx_loop_hook(game->mlx, (void *)ray, game);
	mlx_hook(game->win,  17, 0, (void *)close_win, game);
	mlx_hook(game->win, 2, 1L << 0, (void *)handle_input, game);
	mlx_loop(game->mlx);
	return (0);
}
int		main(int ac, char **av)
{
	t_game	game;
	t_map	map;

	parsing(ac, av, &map);
	if (run_game(&game) != 0)
		return (1);
	return (0);
}
