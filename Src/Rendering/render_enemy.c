#include "cub3d.h"
#include "render.h"
#include "raycasting.h"

void	render_enemy(t_game *game, t_img *img)
{
	t_list	*enemy_lst;
	t_enemy	*enemy;
	double	dist_x;
	double	dist_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	// double	sprite_height;
	double	sprite_pos_x;
	double	sprite_pos_y;

	enemy_lst = game->enemy_lst;
	while (enemy_lst)
	{
		enemy = (t_enemy *) enemy_lst->content;
		dist_x = enemy->pos_x - game->player.pos_x;
		dist_y = enemy->pos_y - game->player.pos_y;
		inv_det = 1 / (game->player.plane_x * game->player.dir_y
			- game->player.plane_y * game->player.dir_x);
		transform_x = inv_det
			* (dist_x * game->player.dir_y - dist_y * game->player.dir_x);
		transform_y = inv_det
			* (-dist_x * game->player.plane_y + dist_y * game->player.plane_x);
		if (transform_y <= 0)
		{
			enemy_lst = enemy_lst->next;
			continue ;
		}
		// sprite_height = SCREEN_HEIGHT / transform_y;
		sprite_pos_x =  SCREEN_WIDTH / 2 * (1 + transform_x / transform_y) - enemy->tex.width / 2;
		sprite_pos_y = SCREEN_HEIGHT / 2 - enemy->tex.height / 2;
		// printf("DEBUG : %f, %f, %f, %f, %f\n", sprite_pos_x, sprite_pos_y, transform_x, transform_y, dist_x, dist_y);
		sprite_to_img(&enemy->tex, img, sprite_pos_x, sprite_pos_y);
		enemy_lst = enemy_lst->next;
	}
}
