#include "map_checker.h"
#include "map_solver.h"
#include "libft.h"

bool    check_valid_char(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (map->arr[i])
    {
        j = 0;
        while (map->arr[i][j])
        {
            if (map->arr[i][j] != '1'  && map->arr[i][j] != '0' 
                && map->arr[i][j] != 'N' && map->arr[i][j] != 'S'
                && map->arr[i][j] != 'E' && map->arr[i][j] != 'W'
                && map->arr[i][j] != ' ')
            {
                ft_putstr_fd("Error\nInvalid map char :", 2);
                ft_putchar_fd(map->arr[i][j], 2);
                ft_putchar_fd('\n', 2);
                return (false);
            }
            j++;
        }
        i++;
    }
    return (true);
}

bool    check_player_count(t_map *map)
{
    int count;
    int i;
    int j;
    count = 0;
    
    i = 0;
    while (map->arr[i])
    {
        j = 0;
        while (map->arr[i][j])
        {
            if (map->arr[i][j] == 'N' || map->arr[i][j] == 'S'
                || map->arr[i][j] == 'E' || map->arr[i][j] == 'W')
                count++;
            j++;
        }
        i++;
    }
    if (count == 1)
        return true;
    else if (count > 1)
        ft_putstr_fd("Error\nToo Much player\n", 2);
    else
        ft_putstr_fd("Error\nPlayer is needed", 2);
    return false;
}

bool     check_map(t_map *map)
{
    if (map->width > MAX_MAP_SIZE || map->height > MAX_MAP_SIZE)
        return (ft_putstr_fd("Error\nMap too high\n", 2), false);
    if (check_valid_char(map) == false)
        return (false);
    if (check_player_count(map) == false)
        return (false);
    solver(map);
    return true;
}