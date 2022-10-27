#ifndef PLAYER_H
# define PLAYER_H

# include "common.h"

typedef struct  s_player
{
    char    up_key;
    char    down_key;
    char    left_key;
    char    right_key;
    int     x;
    int     y;
    int     gate_line;
    int     got_to_gate;
}   t_player;

enum
{
    e_CHANGE,
    e_SET_GATE,
    e_GATE_POS,
    e_GET_X,
    e_GET_Y,
    e_SET_GOAL,
    e_UNSET_GOAL
};

void	edit_map_xy(char edit, int x, int y);
void    print_map(void);

#endif
