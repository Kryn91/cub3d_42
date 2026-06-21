#ifndef FREE_MEMORY_H
# define FREE_MEMORY_H
# include "stdlib.h"
# include "cub3d.h"

void    free_tab(size_t size, char **tab);
void    free_array(char **arr);
void    free_map(t_game *game);
void    free_split(char **str);
#endif