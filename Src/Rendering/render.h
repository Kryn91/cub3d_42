#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# define PIXEL_SIZE 20

void	mlx_pixel_put_img(t_img *img, int x, int y, int color);
void	init_img(t_game *game, t_img *image, int x, int y);
void	render_minimap(t_game *game, t_img *image);
void	sprite_to_img(t_texture *tex, t_img *img, int pos_x, int pos_y);

#endif
