/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:35 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 16:59:40 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "texture_parser.h"

t_type	get_type(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(line + i, "NO ", 3) == 0)
		return (NO);
	if (ft_strncmp(line + i, "SO ", 3) == 0)
		return (SO);
	if (ft_strncmp(line + i, "WE ", 3) == 0)
		return (WE);
	if (ft_strncmp(line + i, "EA ", 3) == 0)
		return (EA);
	if (ft_strncmp(line + i, "F ", 2) == 0)
		return (F);
	if (ft_strncmp(line + i, "C ", 2) == 0)
		return (C);
	return (-1);
}
#include <stdio.h>

t_bool	is_texture(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(line + i, "NO ", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(line + i, "SO ", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(line + i, "WE ", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(line + i, "EA ", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(line + i, "F ", 2) == 0)
		return (TRUE);
	else if (ft_strncmp(line + i, "C ", 2) == 0)
		return (TRUE);
	return (FALSE);
}

char	*get_value(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (str + i);
}

void	handle_texture(char *line_read, t_game *game)
{
	char	*value;
	t_type	type;

	type = get_type(line_read);
	if (type == NO || type == SO || type == WE || type == EA)
	{
		value = get_value(line_read);
		if (!value)
			return ;
		game->map.walls[type].path = ft_strtrim(value, "\n");
	}
	else if (type == C || type == F)
	{
		value = get_value(line_read);
		if (type == C)
			game->map.ceiling_parse = ft_strtrim(value, "\n");
		if (type == F)
			game->map.floor_parse = ft_strtrim(value, "\n");
	}
}
