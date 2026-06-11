#ifndef TEXTURE_PARSER_H
# define TEXTURE_PARSER_H
# include "cub3d.h"

typedef enum    e_type
{
    NO,
    SO,
    WE,
    EA,
    C,
    F
}   e_type;

void	handle_texture(char *line_read, t_game *game);
bool	is_texture(char *line);
#endif