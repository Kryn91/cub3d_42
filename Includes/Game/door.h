#ifndef DOOR_H
# define DOOR_H

typedef struct s_game t_game;

typedef enum e_door
{
	OPEN, CLOSE, PROGRESS, CLOSING
}	e_door;

typedef	struct	s_door
{
	double			x;
	double			y;
	double			progress;
	e_door			state;
	struct s_door	*next;
}	t_door;

void	handle_door(t_game *game);
t_door	*find_door(int x, int y, t_game *game);

#endif
