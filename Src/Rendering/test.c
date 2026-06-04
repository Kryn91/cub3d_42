#include "cub3d.h"
#include "mlx.h"
#include <stddef.h>

#define FOV_PLANE 0.66

static char *g_map_a[] = {
	"1111111",
	"1000001",
	"1011101",
	"1000101",
	"1010101",
	"1000001",
	"1111111",
	NULL
};

static char *g_map_b[] = {
	"1111111111",
	"1000000001",
	"1011111101",
	"1001000101",
	"1011010101",
	"1000000001",
	"1111111111",
	NULL
};

static char *g_map_c[] = {
	"111111111111",
	"100000000001",
	"101111011101",
	"100001000001",
	"101101111101",
	"100000000001",
	"101111111101",
	"111111111111",
	NULL
};

static char *g_map_d[] = {
	"111111111",
	"100000001",
	"101111101",
	"101000101",
	"101011101",
	"101000001",
	"101111101",
	"100000001",
	"111111111",
	NULL
};

typedef struct s_test_scene
{
	char	**map;
	int		width;
	int		height;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}	t_test_scene;

static const t_test_scene g_scenes[] = {
	{g_map_a, 7, 7, 3.5, 3.5, 1.0, 0.0},
	{g_map_a, 7, 7, 1.5, 1.5, 0.0, 1.0},
	{g_map_b, 10, 7, 5.5, 1.5, 0.0, 1.0},
	{g_map_b, 10, 7, 8.5, 5.5, -1.0, 0.0},
	{g_map_c, 12, 8, 2.5, 2.5, 0.7071, 0.7071},
	{g_map_c, 12, 8, 9.5, 5.5, -0.6, 0.8},
	{g_map_d, 9, 9, 4.5, 4.5, 0.0, -1.0}
};

void	init_tex(t_game *game, t_texture *tex, char *path)
{
	tex->path = path;
	tex->height = 64;
	tex->width = 64;
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width, &tex->height);
}

static void	set_player(t_game *game, const t_test_scene *scene)
{
	game->player.pos_x = scene->pos_x;
	game->player.pos_y = scene->pos_y;
	game->player.dir_x = scene->dir_x;
	game->player.dir_y = scene->dir_y;
	game->player.plane_x = -scene->dir_y * FOV_PLANE;
	game->player.plane_y = scene->dir_x * FOV_PLANE;
}

void	init_test(t_game *game, int idx)
{
	int	count;
	const t_test_scene	*scene;

	count = (int)(sizeof(g_scenes) / sizeof(g_scenes[0]));
	if (idx < 0 || idx >= count)
		idx = 0;
	scene = &g_scenes[idx];

	game->screen_x = 1920;
	game->screen_y = 1080;
	game->map.arr = scene->map;
	game->map.floor_color = 0x808080;
	game->map.ceiling_color = 0x333333;
	game->map.width = scene->width;
	game->map.height = scene->height;
	set_player(game, scene);
	game->time = 0;
	game->old_time = 0;
	init_tex(game, game->map.walls, "Textures/tex_brick.xpm");
	init_tex(game, game->map.walls + 1, "Textures/tex_checker.xpm");
	init_tex(game, game->map.walls + 2, "Textures/tex_noise.xpm");
	init_tex(game, game->map.walls + 3, "Textures/tex_stripes.xpm");
}
