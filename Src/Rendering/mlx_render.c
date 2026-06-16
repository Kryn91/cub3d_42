#include "render.h"
#include "mlx.h"

void	mlx_pixel_put_img(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + y * img->size_line + x * (img->bpp / 8);
	*(unsigned int *)pixel = color;
}

void	init_img(t_game *game, t_img *img, int width, int height)
{
	img->img_ptr = mlx_new_image(game->mlx, width, height);
	img->addr = mlx_get_data_addr
		(img->img_ptr, &img->bpp, &img->size_line, &img->endian);
}

void	sprite_to_img(t_texture *tex, t_img *img, int pos_x, int pos_y)
{
	int				i;
	int				j;
	int				x;
	int				y;
	int				draw_pos_x;
	int				draw_pos_y;
	unsigned int	color;

	y = -1;
	while (++y < tex->height)
	{
		x = -1;
		while (++x < tex->width)
		{
			color = *(unsigned int *)(tex->img.addr + y * tex->img.size_line
					+ x * (tex->img.bpp / 8));
			if (color == 0xFF000000)
				continue ;
			j = -1;
			while (++j < PIXEL_SIZE)
			{
				i = -1;
				while (++i < PIXEL_SIZE)
				{
					draw_pos_x = pos_x + x * PIXEL_SIZE + i;
					draw_pos_y = pos_y + y * PIXEL_SIZE + j;
					if (draw_pos_x < 0 || draw_pos_y < 0
						|| draw_pos_x > SCREEN_WIDTH
						|| draw_pos_y > SCREEN_HEIGHT)
						continue ;
					mlx_pixel_put_img(img, draw_pos_x, draw_pos_y, color);
				}
			}
		}
	}
}
