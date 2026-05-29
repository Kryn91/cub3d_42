#include "bool.h"
#include "cub3d.h"
#include <stdio.h>
#include "libft.h"

bool    check_xpm(char *av)
{
    size_t  i;

    i = ft_strlen(av);
    if (av[i] != 'r')
        return (ft_putstr_fd("Error : ber required", 2), false);
    i--;
    if (av[i] != 'e')
        return (ft_putstr_fd("Error : ber required", 2), false);
    i--;
    if (av[i] != 'b')
        return (ft_putstr_fd("Error : ber required", 2), false);
    i--;
    if (av[i] != '.')
        return (ft_putstr_fd("Error : ber required", 2), false);
    return (true);
}

bool    check_valid_arg(int ac, char **av)
{
    if (ac != 2 || av[1][0] == '\0')
        return (false);
    if (check_xpm(av[1]) == false)
        exit(1);
    return (true);
}

void    parsing(int ac, char **av)
{
    if (check_valid_arg(ac, av) == false)
        exit(1);
}