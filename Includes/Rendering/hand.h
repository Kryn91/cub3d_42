/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:43:43 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:43:45 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAND_H
# define HAND_H

# include "render.h"

typedef struct s_hand
{
	int			frame;
	double		last_frame_time;
	int			prepared;
	t_texture	tex[2];
}				t_hand;

#endif
