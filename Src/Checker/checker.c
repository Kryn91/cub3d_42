#include "checker.h"
#include "free_memory.h"
#include "map_checker.h"


void    checker(t_game *game)
{
    if (check_map(game) == false)
    {
        free_map(game);
        exit(1);
    }
}