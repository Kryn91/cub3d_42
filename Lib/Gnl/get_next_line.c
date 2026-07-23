/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <kealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:13:27 by kealves-          #+#    #+#             */
/*   Updated: 2026/07/23 19:59:21 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	read_and_stash(int fd, t_slist **stash)
{
	char	*buff;
	long	readed;

	readed = 1;
	while (!find_newlines(*stash) && readed != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return ;
		readed = (long)read(fd, buff, BUFFER_SIZE);
		if ((*stash == NULL && readed == 0) || (readed == -1))
		{
			free(buff);
			return ;
		}
		buff[readed] = '\0';
		add_to_stash(stash, buff, readed);
		free(buff);
	}
}

void	generate_lines(t_slist *stash, char **line)
{
	long	i;
	long	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	extract_line(t_slist *stash, char **line)
{
	long	i;
	long	j;

	j = 0;
	if (stash == NULL)
		return ;
	generate_lines(stash, line);
	if (line == NULL)
		return ;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_slist **stash)
{
	t_slist	*current;
	t_slist	*clean_node;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (stash == NULL || *stash == NULL)
		return ;
	clean_node = malloc(sizeof(t_slist));
	clean_node->next = NULL;
	current = lst_get_last(*stash);
	while (current->content[i] && current->content[i] != '\n')
		i++;
	if (current->content && current->content[i] == '\n')
		i++;
	clean_node->content = malloc(ft_lstrlen(current->content) - i + 1);
	if (clean_node->content == NULL)
		return ;
	while (current->content[i])
		clean_node->content[j++] = current->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}

char	*get_next_line(int fd)
{
	static t_slist	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	read_and_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
