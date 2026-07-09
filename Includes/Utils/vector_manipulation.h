#ifndef VECTOR_MANIPULATION_H
# define VECTOR_MANIPULATION_H

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

void	normalize_vector(double *x, double *y);

#endif
