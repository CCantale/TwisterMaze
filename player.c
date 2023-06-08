#include "headers/player.h"

void           rand_keys(void);
void           unset_goal(int player);
/* End of static declarations */

static int    player_struct(int which_one, int x, int y, int mode)
{
    static t_player player[2];
    static int      randomizers_pos;

    if (mode == e_GET_KEY)
    {
        return((int)what_key(player[which_one], x));
    }
    else if (mode == e_CHANGE)
    {
        change_pl_pos(player, which_one, x, y);
        //print_map();
    }
    else if (mode == e_SET_GATE)
    {
        player[which_one].gate_line = y;
    }
    else if (mode == e_GATE_POS)
    {
        return (player[which_one].gate_line);
    }
    else if (mode == e_GET_X)
    {
        return (player[which_one].x);
    }
    else if (mode == e_GET_Y)
    {
        return (player[which_one].y);
    }
    else if (mode == e_SET_GOAL)
    {
        player[which_one].got_to_gate = TRUE;
        if (player[(which_one + 1) % 2].got_to_gate == TRUE)
            return (TRUE);
    }
    else if (mode == e_UNSET_GOAL)
    {
        player[which_one].got_to_gate = FALSE;
    }
    else if (mode == e_RAND_KEYS)
    {
        keys_handler(&player[0]);
    }
    else if (mode == e_SET_RAND_POS)
    {
        randomizers_pos *= 100;
        randomizers_pos += y;
    }
    else if (mode == e_GET_RAND_POS)
    {
        return (randomizers_pos);
    }
    return (0);
}

void   init_player(void)
{
    player_struct(PLAYER_ONE, 11, 22, e_CHANGE);
    player_struct(PLAYER_TWO, 50, 22, e_CHANGE);
    unset_goal(PLAYER_ONE);
    unset_goal(PLAYER_TWO);
    rand_keys();
}

void   move_player_to(int player, int x, int y)
{
    player_struct(player, x, y, e_CHANGE);
}

int get_pl_x(int player)
{
    return (player_struct(player, 0, 0, e_GET_X));
}

int get_pl_y(int player)
{
    return (player_struct(player, 0, 0, e_GET_Y));
}

char    get_pl_key(int player, int key)
{
    return ((char)player_struct(player, key, key, e_GET_KEY));
}

void    set_pl_gate(int player, int line)
{
    player_struct(player, 0 , line, e_SET_GATE);
}

int pl_gate_pos(int player)
{
    return (player_struct(player, 0, 0, e_GATE_POS));
}

int    set_goal(int player)
{
    return (player_struct(player, 0, 0, e_SET_GOAL));
}
// returns TRUE if both players got to their gates

void    unset_goal(int player)
{
    player_struct(player, 0, 0, e_UNSET_GOAL);
}

void    rand_keys(void)
{
    player_struct(0, 0, 0, e_RAND_KEYS);
}

void    set_new_randomizer(int pos)
{
    player_struct(pos, pos, pos, e_SET_RAND_POS);
}

int get_rand_pos(void)
{
    return(player_struct(0, 0, 0, e_GET_RAND_POS));
}
