#ifndef MOVES_H
# define MOVES_H

# include "common.h"

char	**get_map(void);
void	edit_map_xy(char edit, int x, int y);
void	print_map(void);
int     get_pl_x(void);
int     get_pl_y(void);
void    move_player_to(int x, int y);

#endif
