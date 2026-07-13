#ifndef SPELL_H
# define SPELL_H

# include "render.h"

typedef struct s_spell
{
	int			frame;
	double		last_frame_time;
	t_texture	tex[3];
}	t_spell;

#endif
