/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:47:18 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 16:03:42 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "delta_time.h"
#include "stdlib.h"
#include "sys/time.h"

double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((double)tv.tv_sec * 1000 + (double)tv.tv_usec / 1000);
}
