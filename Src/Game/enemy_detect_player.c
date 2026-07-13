#include "enemy_detect_player.h"
#include "bool.h"
#include "entity.h"
#include "math.h"
#include "vector_manipulation.h"
#include "enemy_colision.h"

bool    is_in_range(t_game *game, t_entity *enemy)
{
    
    double  dx;
    double  dy;
    double distance;
    
    dx = game->player.pos_x - enemy->pos_x;
    dy = game->player.pos_y - enemy->pos_y;
    distance  = sqrt((dx * dx) + (dy * dy));
    if (distance <= 0.5)
        return (true);
    return (false);
}

bool    check_ray_colision(t_game *game, double ray_x, double ray_y)
{
    char title;

    if (ray_x < 0 || ray_y < 0 ||
            ray_y >= game->map.height ||
            ray_x >= game->map.width)
                return (true); 
    title  = game->map.arr[(int)ray_y][(int)ray_x];
    if (title == '1')
            return (true);
    if (e_check_door(ray_x, ray_y, game))
        return (true);
    return (false);
}
bool    raycast_player(t_game *game, t_entity *enemy)
{
    
    double  dx;
    double  dy;
    double  ray_x;
    double  ray_y;
    
    ray_x = enemy->pos_x;
    ray_y = enemy->pos_y;
    dx = game->player.pos_x - enemy->pos_x;
    dy = game->player.pos_y - enemy->pos_y;
    normalize_vector(&dx, &dy);
    while (1)
    {
        ray_x += dx * 0.05;
        ray_y += dy * 0.05;
        if (check_ray_colision(game, ray_x, ray_y) == true)
            return (false);
        if (fabs(ray_x - game->player.pos_x) < 0.1 &&
            fabs(ray_y - game->player.pos_y) < 0.1)
            return (true);
    }
}

bool    detect_player(t_game *game, t_entity *enemy)
{
    double  dx;
    double  dy;
    double distance;
    
    dx = game->player.pos_x - enemy->pos_x;
    dy = game->player.pos_y - enemy->pos_y;
    distance  = sqrt((dx * dx) + (dy * dy));
    if (distance <= 10 &&  raycast_player(game, enemy) == true)
        return (true);
    return (false);
}