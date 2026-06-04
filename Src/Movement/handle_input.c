#include "handle_input.h"
#include "stdlib.h"

void	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

void    handle_input(int keycode, t_game *game)
{
    double  movespeed;

    movespeed = 0.10;
    if (keycode == KEY_W)
        game->player.pos_y += movespeed;
    else if (keycode == KEY_S)
        game->player.pos_y -= movespeed;
    else if (keycode == KEY_D)
        game->player.pos_x += movespeed;
    else if (keycode == KEY_A)
        game->player.pos_x -= movespeed;
    else if (keycode == KEY_ESC)
        close_win(game);
}
