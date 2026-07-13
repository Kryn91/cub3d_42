#ifndef HAND_H
# define HAND_H

# include "render.h"

typedef struct s_hand
{
	int			frame;
	double		last_frame_time;
	int			prepared;
	t_texture	tex[2];
}	t_hand;

#endif
