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
void	ft_exit(void);
int     set_goal(int player);
void    unset_goal(int player);
char    get_pl_key(int player, int key);
void    check_end_level(int player, char dest);
void    rand_keys(void);


#endif
