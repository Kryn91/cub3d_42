#include "free_memory.h"

void    free_tab(size_t size, char **tab)
{
    size_t  i = 0 ;
    while (i < size)
    {
        free(tab[i]);
        i++;
    }
}

void    free_array(char **arr)
{
    size_t  i = 0 ;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
}