/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <kealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:22:40 by kealves-          #+#    #+#             */
/*   Updated: 2026/07/24 13:23:46 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boolean.h"
#include "check_map.h"
#include "get_next_line.h"

t_bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1')
		return (TRUE);
	else
		return (FALSE);
}

t_bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	finish_gnl(int fd)
{
	char	*line_read;

	line_read = get_next_line(fd);
	while (line_read != NULL)
	{
		free(line_read);
		line_read = get_next_line(fd);
	}
}
