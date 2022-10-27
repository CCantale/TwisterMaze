#include "headers/moves.h"

void move_player_one(char c)
{
    if (c == 'w')
        move_up(PLAYER_ONE);
    else if (c == 's')
        move_down(PLAYER_ONE);
    else if (c == 'a')
        move_left(PLAYER_ONE);
    else if (c == 'd')
        move_right(PLAYER_ONE);
}

void move_player_two(char c)
{
    if (c == 'i')
        move_up(PLAYER_TWO);
    else if (c == 'k')
        move_down(PLAYER_TWO);
    else if (c == 'j')
        move_left(PLAYER_TWO);
    else if (c == 'l')
        move_right(PLAYER_TWO);

}

void   move_up(int player)
{
    char    dest;

    dest = get_map()[get_pl_y(player) - 1][get_pl_x(player)];
    if (dest == ' ')
    {
        move_player_to(player, get_pl_x(player), get_pl_y(player) - 1);
        unset_goal(player);
    }
    if (player == PLAYER_ONE && dest == PLAYER_ONE_GATE
        || player == PLAYER_TWO && dest == PLAYER_TWO_GATE)
    {
        if(set_goal(player))
            ft_exit();
    }
}

void   move_down(int player)
{
    if (get_map()[get_pl_y(player) + 1][get_pl_x(player)] == ' ')
    {
        move_player_to(player, get_pl_x(player), get_pl_y(player) + 1);
        unset_goal(player);
    }
}

void   move_left(int player)
{
    if (get_map()[get_pl_y(player)][get_pl_x(player) - 1] == ' ')
    {
        move_player_to(player, get_pl_x(player) - 1, get_pl_y(player));
        unset_goal(player);
    }
}

void   move_right(int player)
{
    if (get_map()[get_pl_y(player)][get_pl_x(player) + 1] == ' ')
    {
        move_player_to(player, get_pl_x(player) + 1, get_pl_y(player));
        unset_goal(player);
    }
}
