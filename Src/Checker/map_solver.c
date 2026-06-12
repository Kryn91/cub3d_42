#include "map_solver.h"
#include <stdlib.h>
#include "libft.h"

char **cpy_map(char **map, int width, int heigth)
{
    int i;
    int j;
    char    **cpy;
    
    i = 0;
    cpy = malloc(sizeof(char *) * (heigth + 1));
    while (map[i])
    {
        j = 0;
        cpy[i] = malloc(sizeof(char) * (width + 1));
        while (j < width)
        {
            if (map[i][j] != '1'  && map[i][j] != '0' 
                && map[i][j] != 'N' && map[i][j] != 'S'
                && map[i][j] != 'E' && map[i][j] != 'W')
                cpy[i][j] = '_';
            else
                cpy[i][j] = map[i][j];
            j++;
        }
        cpy[i][j] = '\n';
        i++;
    }
    cpy[i] = NULL;
    return (cpy); 
}

void    solver(t_map *map)
{
    char    **map_cpy;

    map_cpy = cpy_map(map->arr, map->width, map->height);
    for (int i =0; map_cpy[i]; i++)
    {
        ft_putstr_fd(map_cpy[i], 1);
    }
}