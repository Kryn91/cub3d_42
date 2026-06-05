#include "handle_input.h"
#include "stdlib.h"
#include <stdio.h>
#include <math.h>

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
        game->player.pos_x -= movespeed;
    else if (keycode == KEY_S)
        game->player.pos_x += movespeed;
    else if (keycode == KEY_D)
        game->player.pos_y -= movespeed;
    else if (keycode == KEY_A)
        game->player.pos_y += movespeed;
    else if (keycode == KEY_ESC)
        close_win(game);
}
void    rotate_player(t_game *game, double angle)
{
    double  old_x;
    double  old_y;
    double  old_plane_x;
    double  old_plane_y;
    
    old_x = game->player.dir_x;
    old_y = game->player.dir_y;
    game->player.dir_x = (old_x * cos(angle))
        - (old_y * sin(angle));
    game->player.dir_y = (old_x * sin(angle))
        + (old_y * cos(angle));
    old_plane_x = game->player.plane_x;
    old_plane_y = game->player.plane_y;
    game->player.plane_x = (old_plane_x * cos(angle))
        - (old_plane_y * sin(angle));
    game->player.plane_y = (old_plane_x * sin(angle))
        + (old_plane_y * cos(angle));
}

void    handle_mouse_input(int x, int y, t_game *game)
{
    (void)y;
    int delta;
    delta = x - game->player.mouse_x;
    game->player.mouse_x = x;
    rotate_player(game, delta * MOUSE_SENSIBILITY);
    //printf("x %d y %d\n", x, y);
}