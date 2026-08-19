/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <kealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:35 by apeterso          #+#    #+#             */
/*   Updated: 2026/08/19 12:55:47 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boolean.h"
#include "get_next_line.h"
#include "libft.h"
#include "texture_parser.h"
#include <inttypes.h>
#include <stdio.h>
#include "free_memory.h"

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

t_bool	color_exist(t_type type, t_game *game)
{
	if (type == C)
	{
		if (game->map.ceiling_parse)
		{
			ft_putstr_fd("Error\nToo much color of ceiling declared\n", 2);
			return (TRUE);
		}
	}
	if (type == F)
	{
		if (game->map.floor_parse)
		{
			ft_putstr_fd("Error\nToo much color of floor declared\n", 2);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	handle_texture(char *line_read, t_game *game)
{
	char	*value;
	t_type	type;

	type = get_type(line_read);
	if (type == NO || type == SO || type == WE || type == EA)
	{
		value = get_value(line_read);
		if (!value)
			return (FALSE);
		if (game->map.walls[type].path)
			return(printf("Error\nMultiple textures set\n"), FALSE);
		game->map.walls[type].path = ft_strtrim(value, "\n");
	}
	else if (type == C || type == F)
	{
		value = get_value(line_read);
		if (color_exist(type, game) == TRUE)
			return (FALSE);
		if (type == C)
			game->map.ceiling_parse = ft_strtrim(value, "\n");
		if (type == F)
			game->map.floor_parse = ft_strtrim(value, "\n");
	}
	return (TRUE);
}
