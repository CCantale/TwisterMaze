#ifndef PLAYER_H
# define PLAYER_H

# include "common.h"
# include "player_struct.h"
# include <stdlib.h>

enum
{
    e_GET_KEY,
    e_CHANGE,
    e_SET_GATE,
    e_GATE_POS,
    e_GET_X,
    e_GET_Y,
    e_SET_GOAL,
    e_UNSET_GOAL,
    e_RAND_KEYS,
    e_SET_RAND_POS,
    e_GET_RAND_POS
};

void    print_map(void);
char    what_key(t_player player, int key);
void    change_pl_pos(t_player *player, int which_one, int x, int y);
void    keys_handler(t_player *player);
void    switch_keys(char *key_one, char *key_two, short *flag);

#endif
