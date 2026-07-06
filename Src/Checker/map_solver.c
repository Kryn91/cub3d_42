#include "map_solver.h"
#include <stdlib.h>
#include "libft.h"
#include "stdio.h"
#include "free_memory.h"
#include "solver.h"

bool    is_valid_char(char c)
{
    if (c != '1' && c != '0' && c != 'N' && c != 'S'
        && c != 'E'&& c != 'W' && c != 'D' && c!= 'O')
        return (false);
    return (true);
}
char **cpy_map(char **map, int width, int heigth)
{
    int i;
    int j;
    char    **cpy;
    
    i = 0;
    cpy = malloc(sizeof(char *) * (heigth + 1)); while (map[i])
    {
        j = 0;
        cpy[i] = malloc(sizeof(char) * (width + 1));
        while (j < width)
        {
            if (j >= (int)ft_strlen(map[i]))
                cpy[i][j] = '_';
            else if (is_valid_char(map[i][j]) == false)
                cpy[i][j] = '_';
            else
                cpy[i][j] = map[i][j];
            j++;
        }
        cpy[i][j] = '\0';
        i++;
    }
    return (cpy[i] = NULL, cpy); 
}

bool check_error(char c)
{
    if (c == '_' || c == '\0')
    {
        printf("Error: map not closed\n");
        return (false);
    }
    return (true);
}

bool    flood_fill(char **map, int start_x, int start_y, int width, int heigth)
{
    t_stack  stack;
    t_point  p; 
    char c;
   
    stack_init(&stack, width * heigth  * 4);
    stack_push(&stack, start_x, start_y);
    while (!stack_empty(&stack)) 
    {
        p = stack_pop(&stack);
        if (p.x < 0 || p.y < 0 || p.y >= heigth || p.x >= width)
            return (printf("Error\nNot a valid Map\n"), false);
        c = map[p.y][p.x];
        if (c == '1' || c == 'X')
            continue;
        if (check_error(c) == false)
            return (free(stack.data), false);
        map[p.y][p.x] = 'X';
        stack_push(&stack, p.x + 1, p.y);
        stack_push(&stack, p.x - 1, p.y);
        stack_push(&stack, p.x, p.y + 1);
        stack_push(&stack, p.x, p.y - 1);
    }
    free(stack.data);
    return true;
}

bool    map_solver(t_game *game)
{
    char    **map_cpy;
    t_map   *map;

    map = &game->map;
    map_cpy = cpy_map(map->arr, map->width, map->height);
    for (int i =0; map_cpy[i]; i++)
    {
        ft_putstr_fd(map_cpy[i], 1);
    }
    if (flood_fill(map_cpy, game->player.pos_x, game->player.pos_y,
            map->width, map->height) == false)
        return (free_array(map_cpy), false);
    free_array(map_cpy);
    return (true);
}