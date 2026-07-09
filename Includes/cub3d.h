#ifndef CUB3D_H
# define CUB3D_H

# include "bool.h"
# include "libft.h"
# include "player.h"
# include "entity.h"
# include "door.h"
# include "render.h"
# include "map.h"

typedef struct s_fps
{
	double	last_frame;
	double	cap;
}	t_fps;

typedef struct s_time
{
	double	last_time;
	double	delta_time;
}	t_time;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_door		*door;
	t_map		map;
	t_input		input;
	t_list		*entity_lst;
	t_time		delta_time;
	t_fps		fps;
	double		time;
	double		old_time;
	t_texture	hand[2];
	t_entity	*projectile;
	double		wall_dist_buf[SCREEN_WIDTH];
	int			hand_frame;
}	t_game;

void	parsing(int ac, char **av, t_game *game);

#endif
