#include "bool.h"
#include "cub3d.h"
#include <stdio.h>
#include "libft.h"
#include "read_map_file.h"
#include "color_parser.h"

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
void debug_map(t_map *map)
{
    int i;

    printf("===== MAP DEBUG =====\n");

    // Dimensions
    printf("width  = %d\n", map->width);
    printf("height = %d\n", map->height);

    // Floor / Ceiling raw
    printf("\n--- COLORS RAW ---\n");
    printf("floor_parse   = %s\n", map->floor_parse);
    printf("ceiling_parse = %s\n", map->ceiling_parse);

    // Floor / Ceiling hex
    printf("\n--- COLORS HEX ---\n");
    printf("floor   = 0x%06X (%d)\n", map->floor_color, map->floor_color);
    printf("ceiling = 0x%06X (%d)\n", map->ceiling_color, map->ceiling_color);

    // Textures
    printf("\n--- TEXTURES ---\n");
    printf("NO = %s\n", map->walls[0].path);
    printf("SO = %s\n", map->walls[1].path);
    printf("WE = %s\n", map->walls[2].path);
    printf("EA = %s\n", map->walls[3].path);

    // Map array
    printf("\n--- MAP ARRAY ---\n");
    if (map->arr)
    {
        for (i = 0; map->arr[i]; i++)
            printf("%s\n", map->arr[i]);
    }

    printf("=====================\n");
}

void    parsing(int ac, char **av, t_game *game)
{
    if (check_valid_arg(ac, av) == false)
        exit(1);
    parse_map(av[1], game);
    color_parser(game);
    debug_map(&game->map);
    if (!game->map.arr)
        exit(1);
}