#include "texture_parsing.h"
#include "libft.h"
#include "free_memory.h"
#include <stdio.h>

bool    check_xpm(char *av)
{
    size_t  i;

    i = ft_strlen(av) - 1;
    ft_strtrim(av, "\n");
    if (av[i] != 'm')
        return (ft_putstr_fd("Error\n.xpm required\n", 2), false);
    i--;
    if (av[i] != 'p')
        return (ft_putstr_fd("Error\n.xpm required\n", 2), false);
    i--;
    if (av[i] != 'x')
        return (ft_putstr_fd("Error\n.xpm required\n", 2), false);
    i--;
    if (av[i] != '.')
        return (ft_putstr_fd("Error\n.xpm required\n", 2), false);
    return (true);
}

void    init_and_check_texture(t_game *game)
{
    printf("NO = %s\nSO = %s\nWE = %s\nEA = %s\nF  = %s\nC  = %s\n",
    game->map.walls[0].path,
    game->map.walls[1].path,
    game->map.walls[2].path,
    game->map.walls[3].path,
    game->map.floor_parse,
    game->map.ceiling_parse);
    if (check_xpm(game->map.walls[0].path) == false)
        return (free_map(game), exit(2));
    if (check_xpm(game->map.walls[1].path) == false)
        return (free_map(game), exit(2));
    if (check_xpm(game->map.walls[2].path) == false)
        return (free_map(game), exit(2));
    if (check_xpm(game->map.walls[3].path) == false)
        return (free_map(game), exit(2));
    //checker si le path exitse    
}