#include "cub3d.h"

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

void	mlx_pixel_put_img(t_img *img, int x, int y, int color);
void	init_img(t_game *game, t_img *image);
void	render_minimap(t_game *game, t_img *image);
