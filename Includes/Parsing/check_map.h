/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kealves- <kealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:26:10 by kealves-          #+#    #+#             */
/*   Updated: 2026/08/19 12:01:32 by kealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H
# include "boolean.h"

t_bool	is_map_line(char *line);
t_bool	is_empty_line(char *line);
void	finish_gnl(int fd);
t_bool	is_only_floor(char *line);

#endif