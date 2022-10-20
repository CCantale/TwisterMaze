#include "headers/moves.h"

static void     move(void)
{
    edit_map_xy(PLAYER_CHAR, get_pl_x(), get_pl_y());
    print_map();
}

void   move_up(void)
{
    if (get_map()[get_pl_y() - 1][get_pl_x()] == ' ')
    {
        edit_map_xy(' ', get_pl_x(), get_pl_y());
        move_player_to(get_pl_x(), get_pl_y() - 1);
        move();
    }
}

void   move_down(void)
{
    if (get_map()[get_pl_y() + 1][get_pl_x()] == ' ')
    {
        edit_map_xy(' ', get_pl_x(), get_pl_y());
        move_player_to(get_pl_x(), get_pl_y() + 1);
        move();
    }
}

void   move_left(void)
{
    if (get_map()[get_pl_y()][get_pl_x() - 1] == ' ')
    {
        edit_map_xy(' ', get_pl_x(), get_pl_y());
        move_player_to(get_pl_x() - 1, get_pl_y());
        move();
    }
}

void   move_right(void)
{
    if (get_map()[get_pl_y()][get_pl_x() + 1] == ' ')
    {
        edit_map_xy(' ', get_pl_x(), get_pl_y());
        move_player_to(get_pl_x() + 1, get_pl_y());
        move();
    }
}
