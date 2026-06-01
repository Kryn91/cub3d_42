/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:02:23 by kealves-          #+#    #+#             */
/*   Updated: 2026/02/02 15:37:55 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_slist
{
	char			*content;
	struct s_slist	*next;
}			t_slist;

void	read_and_stash(int fd, t_slist **stach);
void	generate_lines(t_slist *stash, char **line);
void	extract_line(t_slist *stash, char **line);
void	clean_stash(t_slist **stash);
char	*get_next_line(int fd);
int		find_newlines(t_slist *stash);
t_slist	*lst_get_last(t_slist *stash);
void	add_to_stash(t_slist **stash, char *buff, long readed);
void	free_stash(t_slist *stash);
long	ft_lstrlen(char *str);
#endif
