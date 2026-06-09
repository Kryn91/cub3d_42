#include "cub3d.h"
#include "render.h"
#include "minimap.h"

void	render_minimap(t_game *game, t_img *image)
{
	double	offset_x;
	double	offset_y;
	double	map_x;
	double	map_y;
	int	x;
	int	y;

	y = -1;
	while (++y < MINIMAP_SIZE)
	{
		x = -1;
		while (++x < MINIMAP_SIZE)
		{
			offset_x = x - MINIMAP_SIZE / 2.0;
			offset_y = y - MINIMAP_SIZE / 2.0;
			map_x = game->player.pos_x - offset_x / MINIMAP_TILE_SIZE;
			map_y = game->player.pos_y - offset_y / MINIMAP_TILE_SIZE;
			if (map_x >= 0 && map_x < game->map.width && map_y >= 0 && map_y < game->map.height)
			{
				if (game->map.arr[(int)map_y][(int)map_x] == '0')
					mlx_pixel_put_img(image, MINIMAP_POS_X + x, MINIMAP_POS_Y + y, 0xFFFFFF);
				else
					mlx_pixel_put_img(image, MINIMAP_POS_X + x, MINIMAP_POS_Y + y, 0x000000);
			}
			else
				mlx_pixel_put_img(image, MINIMAP_POS_X + x, MINIMAP_POS_Y + y, 0x1A1A1A);
		}
	}
}
