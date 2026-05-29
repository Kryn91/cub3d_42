#include "bool.h"
#include "cub3d.h"

bool    parsing(int ac, char **av)
{
    if (ac != 2 || av[1][0] == '\0')
        return (false);
    return (true);
}