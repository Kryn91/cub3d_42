#include "init_texture.h"
#include "bool.h"
#include "entity.h"
#include "mlx.h"

void	init_tex(t_game *game, t_texture *tex, char *path)
{
	tex->path = path;
	tex->img.img_ptr = mlx_xpm_file_to_image
		(game->mlx, path, &tex->width, &tex->height);
	tex->img.addr = mlx_get_data_addr(tex->img.img_ptr, &tex->img.bpp,
			&tex->img.size_line, &tex->img.endian);
}

bool	init_enemy_tex(t_game *game, t_list *enemy)
{
	t_list *temp;
	t_entity *entity;
	temp = enemy;
	while (temp)
	{
		entity = ((t_entity *)temp->content);
		if (entity)
		{
			init_tex(game, &entity->tex, "Assets/Entity/Enemy.xpm");
			temp->content = entity;
		}
		temp = temp->next;
	}
	return (true);
}

void	init_texture(t_game *game)
{
	init_tex(game, game->map.walls, game->map.walls[0].path);
	init_tex(game, game->map.walls + 1, game->map.walls[1].path);
	init_tex(game, game->map.walls + 2, game->map.walls[2].path);
	init_tex(game, game->map.walls + 3, game->map.walls[3].path);
	init_tex(game, game->hand.tex, "Assets/Hand/weapon_idle.xpm");
	init_tex(game, game->hand.tex + 1, "Assets/Hand/weapon_attack.xpm");
	init_enemy_tex(game, game->entity_lst);
	game->projectile = malloc(sizeof(t_entity));
	game->projectile->type = PROJECTILE;
	game->projectile->state = 0;
	init_tex(game, &game->projectile->tex, "Assets/Hand/weapon_idle.xpm");
	ft_lstadd_front(&game->entity_lst, ft_lstnew(game->projectile));
}
