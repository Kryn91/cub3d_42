/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:23:55 by apeterso          #+#    #+#             */
/*   Updated: 2026/08/09 16:10:03 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_memory.h"
#include "libft.h"
#include "map_solver.h"
#include "solver.h"
#include "stdio.h"
#include <stdlib.h>

t_bool	is_valid_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
		&& c != 'D' && c != 'O')
		return (FALSE);
	return (TRUE);
}

char	**cpy_map(char **map, int width, int heigth)
{
	int		i;
	int		j;
	char	**cpy;

	i = 0;
	cpy = malloc(sizeof(char *) * (heigth + 1));
	while (map[i])
	{
		j = 0;
		cpy[i] = malloc(sizeof(char) * (width + 1));
		while (j < width)
		{
			if (j >= (int)ft_strlen(map[i]))
				cpy[i][j] = '_';
			else if (is_valid_char(map[i][j]) == FALSE)
				cpy[i][j] = '_';
			else
				cpy[i][j] = map[i][j];
			j++;
		}
		cpy[i][j] = '\0';
		i++;
	}
	return (cpy[i] = NULL, cpy);
}

t_bool	check_error(char c)
{
	if (c == '_' || c == '\0')
	{
		printf("Error\nmap not closed\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	flood_fill(char **map, t_start start, int width, int heigth)
{
	t_stack	stack;
	t_point	p;
	char	c;

	stack_init(&stack, width * heigth * 4);
	stack_push(&stack, start.x, start.y);
	while (!stack_empty(&stack))
	{
		p = stack_pop(&stack);
		if (p.x < 0 || p.y < 0 || p.y >= heigth || p.x >= width)
			return (printf("Error\nNot a valid Map\n"), free(stack.data),
				FALSE);
		c = map[p.y][p.x];
		if (c == '1' || c == 'X')
			continue ;
		if (check_error(c) == FALSE)
			return (free(stack.data), FALSE);
		map[p.y][p.x] = 'X';
		stack_push(&stack, p.x + 1, p.y);
		stack_push(&stack, p.x - 1, p.y);
		stack_push(&stack, p.x, p.y + 1);
		stack_push(&stack, p.x, p.y - 1);
	}
	free(stack.data);
	return (TRUE);
}

t_bool	map_solver(t_game *game)
{
	char	**map_cpy;
	t_map	*map;
	t_start	start;

	map = &game->map;
	map_cpy = cpy_map(map->arr, map->width, map->height);
	start.x = game->player.pos_x;
	start.y = game->player.pos_y;
	if (flood_fill(map_cpy, start, map->width, map->height) == FALSE)
		return (free_array(map_cpy), FALSE);
	free_array(map_cpy);
	return (TRUE);
}
