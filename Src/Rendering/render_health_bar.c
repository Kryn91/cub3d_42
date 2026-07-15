#include "render_health_bar.h"
#include "render.h"
#include "vector_manipulation.h"

void    draw_background(t_img *img, t_vec *vec, int height, int width)
{
    int i;
    int j;
    
    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            mlx_pixel_put_img(img, vec->x + j, vec->y + i,  0x000000);
            j++;
        }
        i++;
    }
}

void    draw_health(t_img *img, t_vec *vec, int hp_width)
{
    int height;
    int i = 0;
    int j = 0;

    height = 15;
    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < hp_width)
        {
            mlx_pixel_put_img(img, vec->x + j, vec->y + i, 0xFF0000);
            j++;
        }
        i++;
    }
}

void    render_health_bar(t_game *game, t_img *img)
{
    t_vec vec;
    int hp_width;

    hp_width = 300 * game->player.hp / 100;
    vec.x = 1000;
    vec.y = 870;
    draw_background(img, &vec, 15, 300);
    draw_health(img, &vec,hp_width);
}
