#include "bool.h"
#include "cub3d.h"
#include <stdio.h>
#include "libft.h"
#include "create_map.h"
#include "texture_parsing.h"

bool    check_cub(char *av)
{
    size_t  i;

    i = ft_strlen(av) - 1;
    if (av[i] != 'b')
        return (ft_putstr_fd("Error\n.cub required", 2), false);
    i--;
    if (av[i] != 'u')
        return (ft_putstr_fd("Error\n.cub required", 2), false);
    i--;
    if (av[i] != 'c')
        return (ft_putstr_fd("Error\n.cub required", 2), false);
    i--;
    if (av[i] != '.')
        return (ft_putstr_fd("Error\n.cub required", 2), false);
    return (true);
}

bool    check_valid_arg(int ac, char **av)
{
    if (ac != 2 || av[1][0] == '\0')
        return (false);
    if (check_cub(av[1]) == false)
        exit(1);
    return (true);
}

void    parsing(int ac, char **av, t_game *game)
{
    if (check_valid_arg(ac, av) == false)
        exit(1);
    game->map.arr = create_map(av[1], game);
    init_and_check_texture(game);
    //checker les texture et init la couleur
    //puis checker la map
    if (!game->map.arr)
        exit(1);
}