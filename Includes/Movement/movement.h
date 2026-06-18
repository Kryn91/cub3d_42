#ifndef MOVEMENT_H
# define MOVEMENT_H
bool	isColiding(double pos_x, double pos_y, t_game *game);
void	move_walk(int keycode, double movespeed, t_game *game);
void	move_strafe(int keycode, double movespeed, t_game *game);
void	handle_arrow(int keycode, t_game *game);
#endif