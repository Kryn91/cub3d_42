#ifndef RENDER_WALLS_H
# define RENDER_WALLS_H

# include "cub3d.h"
# include "raycasting.h"

void	render_door(t_game *game, t_ray *ray, t_img *image, int x);
void	render_walls(t_game *game, t_ray *ray, int x, t_img *image);

#endif
