#include "render.h"
#include "mlx.h"

void	mlx_pixel_put_img(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + y * img->size_line + x * (img->bpp / 8);
	*(unsigned int *)pixel = color;
}

void	init_img(t_game *game, t_img *image)
{
	image->img = mlx_new_image(game->mlx, game->screen_x, game->screen_y);
	image->addr = mlx_get_data_addr(image->img,
			&image->bpp, &image->size_line, &image->endian);
}
