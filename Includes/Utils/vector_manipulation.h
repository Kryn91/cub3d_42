/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_manipulation.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:54:38 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:54:39 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_MANIPULATION_H
# define VECTOR_MANIPULATION_H

typedef struct s_vec
{
	double	x;
	double	y;
}			t_vec;

void		normalize_vector(double *x, double *y);

#endif
