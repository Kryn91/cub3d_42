#ifndef DRAW_H
# define DRAW_H

# include "cub3d.h"

typedef struct s_sprite_draw
{
	int				cur_x;
	int				cur_y;
	int				height;
	int				width;
	int				start_x;
	int				start_y;
	double			tex_x;
	double			tex_y;
	double			tex_step_x;
	double			tex_step_y;
}	t_sprite_draw;

void	draw_entity_sprite(t_game *game, t_img *img,
			t_entity *entity, double size_mod);

#endif
