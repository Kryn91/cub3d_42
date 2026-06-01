#include "libft.h"
#include "cub3d.h"
#include "mlx.h"

int		ray(t_game *game);
void	init_test(t_game *game);

int		main(int ac, char **av)
{
	t_game	game;
	t_map	map;

	(void) ac;
	(void) av;
	parsing(ac, av, &map);
	game.mlx = mlx_init();
	init_test(&game);
	game.win = mlx_new_window(game.mlx, game.screen_x, game.screen_y, "cub3d");
	mlx_loop_hook(game.mlx, (void *)ray, &game);
	mlx_loop(game.mlx);
	return (0);
}
