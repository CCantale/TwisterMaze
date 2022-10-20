#include "headers/player.h"

static int    player_struct(int x, int y, int flag)
{
    static t_player player;

    if (flag == e_CHANGE)
    {
        player.x = x;
        player.y = y;
    }
    else if (flag == e_GET_X)
    {
        return (player.x);
    }
    else if (flag == e_GET_Y)
    {
        return (player.y);
    }
    return (0);
}

void   init_player(void)
{
    player_struct(11, 4, e_CHANGE);
    edit_map_xy(PLAYER_CHAR, 11, 4);
}

void   move_player_to(int x, int y)
{
    player_struct(x, y, e_CHANGE);
}

int get_pl_x(void)
{
    return (player_struct(0, 0, e_GET_X));
}

int get_pl_y(void)
{
    return (player_struct(0, 0, e_GET_Y));
}
