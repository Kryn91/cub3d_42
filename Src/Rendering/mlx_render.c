#include "render.h"
#include "mlx.h"
#include "cub3d.h"

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

void	draw_pixels(t_img *img, unsigned int color, int pos_x, int pos_y)
{
	int	i;
	int	j;

	j = -1;
	while (++j < PIXEL_SIZE)
	{
		i = -1;
		while (++i < PIXEL_SIZE)
		{
			if (pos_x + i < 0 || pos_y + j < 0 || pos_x + i > SCREEN_WIDTH
				|| pos_y + i > SCREEN_HEIGHT)
				continue ;
			mlx_pixel_put_img(img, pos_x + i, pos_y + j, color);
		}
	}
}

void	sprite_to_img(t_texture *tex, t_img *img, int pos_x, int pos_y)
{
	int				x;
	int				y;
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
			draw_pixels(img, color, pos_x + x * PIXEL_SIZE,
				pos_y + y * PIXEL_SIZE);
		}
	}
}
