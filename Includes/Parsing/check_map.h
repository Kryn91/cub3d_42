#ifndef CHECK_MAP_h
# define CHECK_MAP_h
# include "boolean.h"

t_bool is_map_line(char *line);
t_bool is_empty_line(char *line);
void    finish_gnl(int fd);

#endif