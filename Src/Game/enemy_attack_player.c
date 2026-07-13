#include "enemy_attack_player.h"
#include "stdio.h"
#include <sys/time.h>
#include "delta_time.h"


void    attack_player(t_game *game, t_entity *enemy)
{
    double curent_time;

    curent_time = get_time();
    if (curent_time - enemy->spec.e_data.last_attack >= 4000)
    {
        enemy->spec.e_data.last_attack = curent_time;
        game->player.hp -= 20;
        printf("enemy attack Player\n");
        printf("player have %f hp\n", game->player.hp);
    }
    (void)game;
}