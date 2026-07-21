#ifndef RENDER_H
# define RENDER_H

# define PIXEL_SIZE 1
# define SCREEN_WIDTH 1400
# define SCREEN_HEIGHT 900

# include "vector_manipulation.h"

typedef struct s_game t_game;

typedef struct s_img
{
	void	*img_ptr;
	void	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_texture
{
	t_img		img;
	char		*path;
	int			width;
	int			height;
}	t_texture;

void	mlx_pixel_put_img(t_img *img, int x, int y, int color);
void	init_img(t_game *game, t_img *image, int x, int y);
void	render_minimap(t_game *game, t_img *image);
void	sprite_to_img(t_texture *tex, t_img *img, t_vec pos, double size_mod);
void	render_entity(t_game *game, t_img *img);
int		render(t_game *game);
// void	render_doors(t_ray *ray, t_img *image);

#endif
