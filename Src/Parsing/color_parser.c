#include "color_parser.h"
#include "bool.h"
#include "libft.h"
#include "free_memory.h"

bool    check_valid_digit(char  *str)
{
    size_t i;
    i = 0;
    if (ft_strlen(str) <5 || ft_strlen(str) > 11)
        return (ft_putstr_fd("Error\nInvalid color : ", 2)
    , ft_putstr_fd(str, 2), ft_putstr_fd("\b", 2), false);
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != ',')
            return (ft_putstr_fd("Error\nInvalid color:", 2)
        , ft_putstr_fd(str, 2), ft_putstr_fd("\n",2), false);
        i++;
    }
    return true;
}

int rgb_to_hex(int r, int g, int b)
{
    if (r < 0 || r > 255)
        return -1;
    if (g < 0 || g > 255)
        return -1;
    if (b < 0 || b > 255)
        return -1;
    return (r << 16) | (g << 8) | b;
}

int    transform_color(char *str)
{
    int     r;
    int     g;
    int     b;
    char    **split;
    int     color;
    
    split = ft_split(str, ',');
    if (!split)
        return (0);
    if (!split[0] || !split[1] || !split[2])
        return (free_split(split), -1);
    r = ft_atoi(split[0]);
    g = ft_atoi(split[1]);
    b = ft_atoi(split[2]);
    if ((color = (rgb_to_hex(r, g, b))) == -1)
    {
        ft_putstr_fd("Error\nColor is not rgb :", 2);
        ft_putstr_fd(str, 2);
        ft_putstr_fd("\n", 2);
        free_split(split);
        return (-1);
    }
    free_split(split);
    return (color);
}

void    color_parser(t_game *game)
{
    if (check_valid_digit(game->map.ceiling_parse) == false)
    {
        free_map(game);
        free(game);
        exit(1);
    }
    if (check_valid_digit(game->map.floor_parse) == false)
    {
        free_map(game);
        free(game);
        exit(1);
    }
    game->map.ceiling_color = transform_color(game->map.ceiling_parse);
    if (game->map.ceiling_color == -1)
        return (free_map(game), free(game), exit(1));
    game->map.floor_color = transform_color(game->map.floor_parse);
    if (game->map.floor_color == -1)
        return (free_map(game), free(game), exit(1));
}
