#include "headers/player.h"

static void change_pl_pos(t_player *player, int which_one, int x, int y);
void    unset_goal(int player);
////////////////////

static int    player_struct(int which_one, int x, int y, int mode)
{
    static t_player player[2];

    if (mode == e_CHANGE)
    {
        change_pl_pos(player, which_one, x, y);
        print_map();
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
    return (0);
}

static void change_pl_pos(t_player player[], int which_one, int x, int y)
{
    char avatar;

    if (which_one == PLAYER_ONE)
        avatar = PLAYER_ONE_CHAR;
    else
        avatar = PLAYER_TWO_CHAR;
    edit_map_xy(' ', player[which_one].x, player[which_one].y);
    player[which_one].x = x;
    player[which_one].y = y;
    edit_map_xy(avatar, player[which_one].x, player[which_one].y);
}

void   init_player(void)
{
    player_struct(PLAYER_ONE, 11, 22, e_CHANGE);
    player_struct(PLAYER_TWO, 50, 22, e_CHANGE);
    unset_goal(PLAYER_ONE);
    unset_goal(PLAYER_TWO);
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

void    set_pl_gate(int player, int line)
{
    player_struct(player, 0 , line, e_SET_GATE);
}

void    pl_gate_pos(int player)
{
    player_struct(player, 0, 0, e_GATE_POS);
}

int    set_goal(int player)
{
    return (player_struct(player, 0, 0, e_SET_GOAL));
}

void    unset_goal(int player)
{
    player_struct(player, 0, 0, e_UNSET_GOAL);
}
