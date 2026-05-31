#include "stddef.h"
#include "cub3d.h"

static char *map[] =
{
	"111111",
	"100001",
	"101001",
	"100001",
	"111111",
	NULL
};

typedef struct s_test_case
{
	double pos_x, pos_y;
	double dir_x, dir_y;
	double plane_x, plane_y;
}	t_test_case;

static const t_test_case g_tests[] = {
	{3.1, 2.1,  0.0,  1.0, -0.66,  0.0},
	{3.1, 2.1,  1.0,  0.0,  0.0,   0.66},
	{3.1, 2.1,  0.0, -1.0,  0.66,  0.0},
	{3.1, 2.1, -1.0,  0.0,  0.0,  -0.66},
	{2.5, 2.5,  0.7,  0.7, -0.46,  0.46},
};

void	init_test(t_game *game)
{
	int idx = 1;

	game->screen_x = 1920;
	game->screen_y = 1080;
	game->map.arr = map;
	game->map.floor_color = 0x808080;
	game->map.ceiling_color = 0x333333;
	game->map.width = 6;
	game->map.height = 5;
	game->player.pos_x = g_tests[idx].pos_x;
	game->player.pos_y = g_tests[idx].pos_y;
	game->player.dir_x = g_tests[idx].dir_x;
	game->player.dir_y = g_tests[idx].dir_y;
	game->player.plane_x = g_tests[idx].plane_x;
	game->player.plane_y = g_tests[idx].plane_y;
	game->time = 0;
	game->old_time = 0;
}
