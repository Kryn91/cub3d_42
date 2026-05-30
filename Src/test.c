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

void	init_test(t_game *game)
{
	game->screen_x = 1200;
	game->screen_y = 800;
	game->map.arr = map;
	game->map.floor_color = 0x808080;
	game->map.ceiling_color = 0x333333;
	game->map.width = 6;
	game->map.height = 5;
	game->player.pos_x = 3.0;
	game->player.pos_y = 2.0;
	game->player.dir_x = 0.0;
	game->player.dir_y = 1.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
	game->time = 0;
	game->old_time = 0;
}
