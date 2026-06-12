#include "init_player.h"

void    set_orientation(char c, t_game *game)
{
    if (c == 'E')
        game->player.rotation_angle = 0;
    if (c == 'S')
        game->player.rotation_angle = 90;
    if (c == 'W')
        game->player.rotation_angle = 180;
    if (c == 'N')
        game->player.rotation_angle = 270;
}

void    set_player_pos(t_game  *game)
{
    int y;
    int x;
    t_map   *map;

    y = 0;
    map = &game->map;
    while (map->arr[y])
    {
        x = 0;
        while (map->arr[y][x])
        {
            if (map->arr[y][x] == 'N' || map->arr[y][x] == 'S' 
                || map->arr[y][x] == 'E' || map->arr[y][x] == 'W')
            {
                set_orientation(map->arr[y][x], game);
                game->player.pos_x = x;
                game->player.pos_y = y;
            }
            x++;
        }
        y++;
    }
}
void    init_player(t_game *game)
{
    set_player_pos(game);
}