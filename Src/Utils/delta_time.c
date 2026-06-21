#include <stddef.h>
#include "sys/time.h"
#include "cub3d.h"

double  get_time(void)
{
    struct  timeval tv;
    gettimeofday(&tv, NULL);
    return ((double)tv.tv_sec  + (double)tv.tv_usec / 1000000.0);
}

void    set_delta_time(t_game *game)
{
    double current = get_time();
    game->delta_time.delta_time =  (current - game->delta_time.last_time) / 1000;
    game->delta_time.last_time = current;
}

