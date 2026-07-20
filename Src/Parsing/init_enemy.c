#include "init_enemy.h"
#include "free_list.h"
#include "free_memory.h"
#include "entity.h"
#include "libft.h"
#include "delta_time.h"

t_entity    *create_entity(int x, int y)
{
    t_entity    *content;

    content = malloc(sizeof(t_entity));
    if (!content)
        return (NULL);
    content  = ft_memset(content, 0, sizeof(t_entity));
    if (!content)
        return (NULL);
    content->type = ENEMY;
    content->state = 1;
    content->pos_x = x + 0.5;
    content->pos_y = y + 0.5;
    content->dir_x = -1;
    content->dir_y = 0;
    content->estate = PATROL;
    content->spec.e_data.hp = 100;
    content->spec.e_data.hit_radius = 0.5;
    content->frame = 0;
    content->last_frame_time = get_time();
    return (content);
}

void    enemy_add_back(int y, int x, t_list **enemy)
{
    t_list      *tmp;
    t_list      *new;

    if (!enemy)
        return ;
    new = malloc(sizeof(t_list));
    if (!new)
        return ;
    new->content = create_entity(x, y);
    if (!new->content)
        return ;
    new->next = NULL;
    if (!*enemy)
    {
        *enemy = new;
        return ;
    }
    tmp = *enemy;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

int create_enemy(char **map, t_list **enemy)
{
    int x;
    int y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'O')
                enemy_add_back(y, x, enemy);
            x++;
        }
        y++;
    }
    return (0);
    return (0);
}
#include <stdio.h>

/*void    print_entities(t_list *list)
{
    t_entity    *entity;
    int         i;

    i = 0;
    while (list)
    {
        entity = (t_entity *)list->content;

        if (entity)
        {
            printf("------ Entity %d ------\n", i);
            printf("Type        : %d\n", entity->type);
            printf("State       : %d\n", entity->state);
            printf("Position    : (%f, %f)\n", entity->pos_x, entity->pos_y);
            printf("Transform   : (%f, %f)\n",
                entity->transform_x, entity->transform_y);
            printf("HP          : %f\n", entity->spec.e_data.hp);
        }
        else
            printf("Entity %d : NULL\n", i);

        list = list->next;
        i++;
    }
}*/

void    init_enemy(t_game *game)
{
   t_list *enemy;
   enemy = NULL;
   int  state;

    state = create_enemy(game->map.arr, &enemy);
    if (state == 1)
    {
        free_map(game);
        free_door(game->door);
        exit (1);
    }
    game->entity_lst = enemy;
    //print_entities(game->entity_lst);
}
