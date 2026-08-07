/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <kealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:38:07 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/24 14:30:11 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_PARSER_H
# define TEXTURE_PARSER_H
# include "cub3d.h"

typedef enum e_type
{
	NO,
	SO,
	WE,
	EA,
	C,
	F
}		t_type;

t_bool	handle_texture(char *line_read, t_game *game);
t_bool	is_texture(char *line);

#endif
