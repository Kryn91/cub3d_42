#include "delta_time.h"
#include "sys/time.h"
#include "stdlib.h"

double  get_time(void)
{
    struct  timeval tv;
    gettimeofday(&tv, NULL);
    return ((double)tv.tv_sec * 1000 + (double)tv.tv_usec / 1000);
}