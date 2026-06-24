#include "free_memory.h"
#include "init_door.h"
#include <stdio.h>

void    lst_add_back(int y, int x, t_door **door)
{
    t_door *tmp;
    t_door  *new;

    if (!door)
        return ;
    new = malloc(sizeof(t_door));
    if (!new)
        return ;
    new->x = x;
    new->y = y;
    new->state = CLOSE;
    new->progress = 0.1;
    new->next = NULL;
    if (!*door)
    {
        *door = new;
        return ;
    }
    tmp = *door;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

int create_door(char **map, t_door **door)
{
    int x;
    int y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'D')
                lst_add_back(y, x, door);
            x++;
        }
        y++;
    }
    return (0);
}

void	debug_doors(t_game *game)
{
	t_door	*door;
	int		i;

	door = game->door;
	i = 0;

	printf("========== DOORS ==========\n");

	while (door)
	{
		printf(
			"[%d] x=%f y=%f state=%d progress=%.2f\n",
			i,
			door->x,
			door->y,
			door->state,
			door->progress
		);
		door = door->next;
		i++;
	}

	printf("Total doors: %d\n", i);
	printf("===========================\n");
}

void    init_door(t_game *game)
{
   t_door *door;
   door = NULL;
   int state;

    state = create_door(game->map.arr, &door);
    if (state == -1)
    {
        free_map(game);
        exit (1);
    }
    game->door = door;
    debug_doors(game);
}
