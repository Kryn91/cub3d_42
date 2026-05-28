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
	game->map.arr = map;
	game->map.floor_color = 0x808080;
	game->map.ceiling_color = 0x333333;
	game->player.pos_x = 2.0;
	game->player.pos_y = 2.0;
	game->player.dir_x = -1.0;
	game->player.dir_y = 0.0;
	game->player.cam_x = 0.0;
	game->player.cam_y = 0.66;
	game->time = 0;
	game->old_time = 0;
}
