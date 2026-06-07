#ifndef HANDLE_INPUT_H
#define HANDLE_INPUT_H

#include "cub3d.h"
#include "mlx.h"

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_ESC	65307

# define MOUSE_SENSIBILITY 0.005

void    handle_input(int keycode, t_game *game);
void	close_win(t_game *game);
void    handle_mouse_input(int x, int y, t_game *game);
#endif
