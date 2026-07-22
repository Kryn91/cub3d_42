/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:47:39 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:47:39 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "vector_manipulation.h"

void	normalize_vector(double *x, double *y)
{
	double	length;

	length = sqrt(((*x) * (*x) + ((*y) * (*y))));
	if (length == 0)
	{
		*x = 0;
		*y = 0;
		return ;
	}
	*x /= length;
	*y /= length;
}
