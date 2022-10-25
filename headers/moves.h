#ifndef MOVES_H
# define MOVES_H

# include "common.h"

char	**get_map(void);
int     get_pl_x(int player);
int     get_pl_y(int player);
void    move_player_to(int player, int x, int y);
void    move_up(int player);
void    move_down(int player);
void    move_left(int player);
void    move_right(int player);


#endif
