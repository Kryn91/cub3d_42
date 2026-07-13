#ifndef ATTACK_H
# define ATTACK_H

#include "cub3d.h"

void	shoot(t_game *game);
void	projectile_update(t_game *game);
void	handle_mouse(int button, int x, int y, void *param);

#endif
