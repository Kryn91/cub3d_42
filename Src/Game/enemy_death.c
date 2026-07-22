#include "enemy_death.h"
#include "mlx.h"

void	entity_death(t_game *game, t_entity *entity, t_list *prev, t_list **cur)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (i < 3)
	{
		if (entity->tex[i].img.img_ptr)
			mlx_destroy_image(game->mlx, entity->tex[i].img.img_ptr);
		i++;
	}
	if (prev == NULL)
		game->entity_lst = (*cur)->next;
	else
		prev->next = (*cur)->next;
	free(entity);
	tmp = (*cur)->next;
	free(*cur);
	*cur = tmp;
}

void	free_dead_enemies(t_game *game)
{
	t_list		*entity_lst;
	t_list		*tmp;
	t_entity	*entity;

	entity_lst = game->entity_lst;
	tmp = NULL;
	while (entity_lst)
	{
		entity = (t_entity *)entity_lst->content;
		if (entity->state == 0)
		{
			entity_death(game, entity, tmp, &entity_lst);
			continue ;
		}
		tmp = entity_lst;
		entity_lst = entity_lst->next;
	}
}
