#include "free_list.h"
#include <stdlib.h>

void    free_door(t_door *door)
{
    t_door  *tmp;
    t_door  *next;

    tmp = door;
    while (tmp)
    {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
}