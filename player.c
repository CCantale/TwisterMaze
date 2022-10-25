#include "headers/player.h"

static void change_pl_pos(t_player *player, int which_one, int x, int y);
////////////////////

static int    player_struct(int which_one, int x, int y, int flag)
{
    static t_player player[2];

    if (flag == e_CHANGE)
    {
        change_pl_pos(player, which_one, x, y);
        print_map();
    }
    else if (flag == e_GET_X)
    {
        return (player[which_one].x);
    }
    else if (flag == e_GET_Y)
    {
        return (player[which_one].y);
    }
    else if (flag == e_EXIT)
    {
        ft_free(player);
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

void free_player(void)
{
    player_struct(0, 0, 0, e_EXIT);
}
