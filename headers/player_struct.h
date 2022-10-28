#ifndef PLAYER_STRUCT_H
# define PLAYER_STRUCT_H

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

#endif
