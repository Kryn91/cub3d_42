#include "checker.h"
#include "free_memory.h"
#include "map_checker.h"
#include <unistd.h>

bool    check_path(t_game *game)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (access(game->map.walls[i].path, F_OK) == -1)
        {
            ft_putstr_fd("Error\nIncorect path :", 2);
            ft_putstr_fd(game->map.walls[i].path, 2);
            ft_putstr_fd("\n", 2);
            return (false);
        }
        i++;
    }
    return (true);
}

void    checker(t_game *game)
{   
    if (check_path(game) == false)
    {
        free_map(game);
        exit(1);
    }
    if (check_map(game) == false)
    {
        free_map(game);
        exit(1);
    }
}