#include "cub3d.h"
#include "mlx.h"

void	init_tex(t_game *game, t_texture *tex, char *path)
{
	tex->path = path;
	tex->height = 64;
	tex->width = 64;
	tex->img.img_ptr = mlx_xpm_file_to_image
		(game->mlx, path, &tex->width, &tex->height);
	tex->img.addr = mlx_get_data_addr(tex->img.img_ptr, &tex->img.bpp,
			&tex->img.size_line, &tex->img.endian);
}

void	init_hand_tex(t_game *game, char *path, int i)
{
	t_texture	*tex;

	tex = game->hand + i;
	tex->path = path;
	tex->height = 16;
	tex->width = 16;
	tex->img.img_ptr = mlx_xpm_file_to_image
		(game->mlx, path, &tex->width, &tex->height);
	tex->img.addr = mlx_get_data_addr(tex->img.img_ptr, &tex->img.bpp,
			&tex->img.size_line, &tex->img.endian);
}

void	init(t_game *game)
{
	game->screen_x = 1600;
	game->screen_y = 920;
	init_tex(game, game->map.walls, game->map.walls[0].path);
	init_tex(game, game->map.walls + 1, game->map.walls[1].path);
	init_tex(game, game->map.walls + 2, game->map.walls[2].path);
	init_tex(game, game->map.walls + 3, game->map.walls[3].path);
	init_hand_tex(game, "Assets/Hand/weapon_idle.xpm", 0);
	init_hand_tex(game, "Assets/Hand/weapon_attack.xpm", 1);
}
