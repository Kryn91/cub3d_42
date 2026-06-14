#include "init_player.h"
#include "math.h"

#define FOV_PLANE 0.66

void    set_orientation(char c, t_game *game)
{
    if (c == 'E')
    {
        game->player.dir_x = 0;
        game->player.dir_y = 1;
        game->player.rotation_angle = 0.0;
    }
    if (c == 'S')
    {
        game->player.dir_x = -1;
        game->player.dir_y = 0;
        game->player.rotation_angle = (M_PI / 2);
    }
    if (c == 'W')
    {
        game->player.dir_x = 0;
        game->player.dir_y = -1;
        game->player.rotation_angle = (M_PI);
    }
    if (c == 'N')
    {
        game->player.dir_x = 1;
        game->player.dir_y = 0;
        game->player.rotation_angle = (3.0 * M_PI / 2);
    }
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
                game->player.pos_x = x + 0.5;
                game->player.pos_y = y + 0.5;
            }
            x++;
        }
        y++;
    }
}

void    set_camera_plane(t_game *game)
{
    game->player.plane_x = -game->player.dir_y * FOV_PLANE;
    game->player.plane_y = game->player.dir_x * FOV_PLANE;
}

void    init_player(t_game *game)
{
    set_player_pos(game);
    set_camera_plane(game);
}
