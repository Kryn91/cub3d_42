# include "boolean.h"

t_bool is_map_line(char *line)
{
    int i;

    i = 0;
	while (line[i] == ' ' || line[i] == '\t')
    	i++;
	if (line[i] == '1')
		return (TRUE);
	else
		return (FALSE);
}

t_bool is_empty_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return (FALSE);
        i++;
    }
    return (TRUE);
}