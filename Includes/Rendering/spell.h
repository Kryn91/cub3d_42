/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:44:51 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:44:51 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELL_H
# define SPELL_H

# include "render.h"

typedef struct s_spell
{
	int			frame;
	double		last_frame_time;
	t_texture	tex[3];
}				t_spell;

#endif
