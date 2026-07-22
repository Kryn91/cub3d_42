/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeterso <apeterso@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:21:37 by apeterso          #+#    #+#             */
/*   Updated: 2026/07/22 15:22:43 by apeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_H
# define DOOR_H

typedef struct s_game	t_game;

typedef enum e_edoor
{
	OPEN,
	CLOSE,
	PROGRESS,
	CLOSING
}						t_edoor;

typedef struct s_door
{
	double				x;
	double				y;
	double				progress;
	t_edoor				state;
	struct s_door		*next;
}						t_door;

void					handle_door(t_game *game);
t_door					*find_door(int x, int y, t_game *game);

#endif
