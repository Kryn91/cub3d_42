#include "free_memory.h"

void    free_tab(size_t size, char **tab)
{
    size_t  i = 0 ;
    while (i < size)
    {
        free(tab[i]);
        i++;
    }
}

void    free_array(char **arr)
{
    size_t  i = 0 ;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
}

void    free_map(t_game *game)
{
    if (game->map.arr)
        free_array(game->map.arr);
    if (game->map.walls[0].path)
        free(game->map.walls[0].path);
    if (game->map.walls[1].path)
        free(game->map.walls[1].path);
    if (game->map.walls[2].path)
        free(game->map.walls[2].path);
    if (game->map.walls[3].path)
        free(game->map.walls[3].path);
    if (game->map.ceiling_parse)
        free(game->map.ceiling_parse);
    if (game->map.floor_parse)
        free(game->map.floor_parse);
}
