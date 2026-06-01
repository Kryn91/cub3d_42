/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:24:31 by kealves-          #+#    #+#             */
/*   Updated: 2026/02/02 15:33:18 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newlines(t_slist *stash)
{
	int		i;
	t_slist	*current;

	i = 0;
	if (stash == NULL)
		return (0);
	current = lst_get_last(stash);
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_slist	*lst_get_last(t_slist *stash)
{
	t_slist	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	add_to_stash(t_slist **stash, char *buff, long readed)
{
	t_slist	*last;
	t_slist	*new_node;
	int		i;

	i = 0;
	new_node = malloc(sizeof(t_slist));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	if (new_node->content == NULL)
		return ;
	while (buff[i] && i < readed)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = lst_get_last(*stash);
	last->next = new_node;
}

void	free_stash(t_slist *stash)
{
	t_slist	*current;
	t_slist	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

long	ft_lstrlen(char *str)
{
	long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
