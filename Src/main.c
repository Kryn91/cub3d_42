#include "libft.h"
#include "cub3d.h"
#include "mlx.h"
#include "bool.h"

int main(int ac, char **av)
{
	t_game	game;

	parsing(ac, av);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1200, 600, "cub3d");
	mlx_loop(game.mlx);
	return (0);
}