#ifndef PLAYER_H
# define PLAYER_H

# include "bool.h"

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	mouse_x;
	double	mouse_y;
	double	rotation_angle;
}	t_player;

typedef struct s_input
{
	bool	A;
	bool	D;
	bool	W;
	bool	S;
	bool	E;
}   t_input;

#endif
