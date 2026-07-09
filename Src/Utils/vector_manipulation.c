# include "vector_manipulation.h"
# include "math.h"

void    normalize_vector(double *x, double *y)
{
    double length;
        
    length  = sqrt(((*x) * (*x) + ((*y) * (*y))));
    if (length == 0)
    {
       *x = 0;
       *y = 0; 
        return ;
    }
    *x /= length;
    *y /= length;
}