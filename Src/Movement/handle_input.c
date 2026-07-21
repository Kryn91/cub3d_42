#include "handle_input.h"
#include "init_texture.h"
#include "libft.h"
#include "movement.h"
#include "render.h"
#include "stdlib.h"
#include <math.h>
#include "free_memory.h"
#include "free_list.h"
#include "mlx.h"
#include "vector_manipulation.h"

void	close_win(t_game *game)
{
	free_texture(game);	
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_lstclear(&game->entity_lst, free_entity);
	free_map(game);
	free_door(game->door);
	free(game->mlx);
	exit(0);
}

void	rotate_player(t_game *game, double angle)
{
	double	old_x;
	double	old_y;
	double	old_plane_x;
	double	old_plane_y;

	old_x = game->player.dir_x;
	old_y = game->player.dir_y;
	game->player.dir_x = (old_x * cos(angle)) - (old_y * sin(angle));
	game->player.dir_y = (old_x * sin(angle)) + (old_y * cos(angle));
	old_plane_x = game->player.plane_x;
	old_plane_y = game->player.plane_y;
	game->player.plane_x = (old_plane_x * cos(angle)) - (old_plane_y
			* sin(angle));
	game->player.plane_y = (old_plane_x * sin(angle)) + (old_plane_y
			* cos(angle));
	game->player.rotation_angle += angle;
}

void	handle_arrow(int keycode, t_game *game)
{
	if (keycode == KEY_RIGHT)
		rotate_player(game, 0.10);
	if (keycode == KEY_LEFT)
		rotate_player(game, -0.10);
}

void	key_press(int keycode, t_game *game)
{
	handle_arrow(keycode, game);
	if (keycode == KEY_A)
		game->input.A = true;
	if (keycode == KEY_D)
		game->input.D = true;
	if (keycode == KEY_S)
		game->input.S = true;
	if (keycode == KEY_W)
		game->input.W = true;
	if (keycode == KEY_E)
		game->input.E = true;
	else if (keycode == KEY_ESC)
		close_win(game);
}

void	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->input.A = false;
	if (keycode == KEY_D)
		game->input.D = false;
	if (keycode == KEY_S)
		game->input.S = false;
	if (keycode == KEY_W)
		game->input.W = false;
	if (keycode == KEY_E)
		game->input.E = false;
}

void handle_mouse_input(int x, int y, t_game *game)
{
    int center_x = SCREEN_WIDTH / 2;
    int center_y = SCREEN_HEIGHT / 2;

    int delta = x - game->player.mouse_x;
    game->player.mouse_x = x;

    if (x == center_x && y == center_y)
        return;

    rotate_player(game, delta * MOUSE_SENSIBILITY);

    mlx_mouse_move(game->mlx, game->win, center_x, center_y);
}
