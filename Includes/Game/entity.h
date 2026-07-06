#ifndef ENTITY_H
# define ENTITY_H

# define ENEMY_PATH "chemin/a mettre"
# include "render.h"

typedef struct s_projectile_data
{
	double	dir_x;
	double	dir_y;
}	t_projectile_data;

typedef struct s_enemy_data
{
	double	hp;
	double	hit_radius;
}	t_enemy_data;

typedef union u_entity_spec
{
	t_enemy_data		e_data;
	t_projectile_data	p_data;
}	t_entity_spec;

typedef enum e_entity_type
{
	ENEMY,
	PROJECTILE
}	t_entity_type;

typedef struct s_entity
{
	t_entity_type	type;
	double			pos_x;
	double			pos_y;
	double			transform_x;
	double			transform_y;
	int				state;
	t_texture		tex;
	t_entity_spec	spec;
}	t_entity;

#endif
