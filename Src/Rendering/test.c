#include "cub3d.h"
#include "mlx.h"

void	init_tex(t_game *game, t_texture *tex, char *path)
{
	tex->path = path;
	tex->img.img_ptr = mlx_xpm_file_to_image
		(game->mlx, path, &tex->width, &tex->height);
	tex->img.addr = mlx_get_data_addr(tex->img.img_ptr, &tex->img.bpp,
			&tex->img.size_line, &tex->img.endian);
}

void	init(t_game *game)
{
	t_enemy	*enemy1;
	t_enemy	*enemy2;

	init_tex(game, game->map.walls, game->map.walls[0].path);
	init_tex(game, game->map.walls + 1, game->map.walls[1].path);
	init_tex(game, game->map.walls + 2, game->map.walls[2].path);
	init_tex(game, game->map.walls + 3, game->map.walls[3].path);
	init_tex(game, game->hand, "Assets/Hand/weapon_idle.xpm");
	init_tex(game, game->hand + 1, "Assets/Hand/weapon_attack.xpm");
	enemy1 = malloc(sizeof(t_enemy));
	enemy2 = malloc(sizeof(t_enemy));
	enemy1->pos_x = 25.5;
	enemy1->pos_y = 4.5;
	init_tex(game, &enemy1->tex, "Assets/Hand/weapon_attack.xpm");
	enemy2->pos_x = 27.3;
	enemy2->pos_y = 4.7;
	init_tex(game, &enemy2->tex, "Assets/Hand/weapon_attack.xpm");
	ft_lstadd_front(&game->enemy_lst, ft_lstnew(enemy1));
	ft_lstadd_front(&game->enemy_lst, ft_lstnew(enemy2));
}
