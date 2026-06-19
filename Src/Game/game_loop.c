#include "game_loop.h"
#include "movement.h"
#include "render.h"

int game_loop(t_game *game)
{
    move_player(game);
    render(game);
    return (0);
}