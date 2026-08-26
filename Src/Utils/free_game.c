#include "free_list.h"
#include "free_game.h"
#include "free_memory.h"
#include "mlx.h"

void	free_game(t_game *game)
{
	free_texture(game);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free_map(game);
	ft_lstclear(&game->entity_lst, free_entity);
	free_door(game->door);
	free(game);
}
