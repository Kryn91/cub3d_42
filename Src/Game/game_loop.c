#include "game_loop.h"
#include "movement.h"
#include "delta_time.h"
#include "door.h"
#include "render.h"
#include "interact.h"

int game_loop(t_game *game)
{
    double  now;
    
    now  = get_time();
    if (now - game->fps.last_frame < 1.0 / 60.0)
        return (0);
    game->fps.last_frame = now;
    set_delta_time(game);
    move_player(game);
    interact(game);
    handle_door(game);
    render(game);
    return (0);
}