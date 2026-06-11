#include "libft.h"
#include "texture_parser.h"
#include "get_next_line.h"

e_type get_type(char *line)
{
    if (ft_strncmp(line, "NO ", 3) == 0)
        return NO;
    if (ft_strncmp(line, "SO ", 3) == 0)
        return SO;
    if (ft_strncmp(line, "WE ", 3) == 0)
        return WE;
    if (ft_strncmp(line, "EA ", 3) == 0)
        return EA;
    if (ft_strncmp(line, "F ", 2) == 0)
        return F;
    if (ft_strncmp(line, "C ", 2) == 0)
        return C;
    return -1;
}

bool	is_texture(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
        return (true);
	else if (ft_strncmp(line, "SO ", 3) == 0)
        return (true);
	else if (ft_strncmp(line, "WE ", 3) == 0)
        return (true);
	else if (ft_strncmp(line, "EA ", 3) == 0)
        return (true);
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (true);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (true);
	return (false);
}

char	*get_value(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return NULL;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] == ' '|| str[i] == '\t')
		i++;
	return (str + i);
}

void	handle_texture(char *line_read, t_game *game)
{
	char	*value;
	e_type	type;

	type = get_type(line_read);
	if (type == NO || type == SO || type == WE || type == EA)
	{
		value = get_value(line_read);
		if (!value)
			return ;
		game->map.walls[type].path = ft_strtrim(value, "\n");
	}
	else if (type == C || type == F)
	{
		value = get_value(line_read);
		if (type == C)
			game->map.ceiling_parse = ft_strtrim(value, "\n");
		if (type == F)
			game->map.floor_parse = ft_strtrim(value, "\n");
	}
}
