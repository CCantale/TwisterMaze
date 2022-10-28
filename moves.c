#include "headers/moves.h"

void move_player_one(char c)
{
    if (c == get_pl_key(PLAYER_ONE, UP_KEY))
        move_up(PLAYER_ONE);
    else if (c == get_pl_key(PLAYER_ONE, DOWN_KEY))
        move_down(PLAYER_ONE);
    else if (c == get_pl_key(PLAYER_ONE, LEFT_KEY))
        move_left(PLAYER_ONE);
    else if (c == get_pl_key(PLAYER_ONE, RIGHT_KEY))
        move_right(PLAYER_ONE);
}

void move_player_two(char c)
{
    if (c == get_pl_key(PLAYER_TWO, UP_KEY))
        move_up(PLAYER_TWO);
    else if (c == get_pl_key(PLAYER_TWO, DOWN_KEY))
        move_down(PLAYER_TWO);
    else if (c == get_pl_key(PLAYER_TWO, LEFT_KEY))
        move_left(PLAYER_TWO);
    else if (c == get_pl_key(PLAYER_TWO, RIGHT_KEY))
        move_right(PLAYER_TWO);

}

void   move_up(int player)
{
    char    dest;

    dest = get_map()[get_pl_y(player) - 1][get_pl_x(player)];
    if (dest == ' ' || dest == KEY_RANDOMIZER)
    {
        if (dest == KEY_RANDOMIZER)
            rand_keys();
        move_player_to(player, get_pl_x(player), get_pl_y(player) - 1);
        unset_goal(player);
    }
    check_end_level(player, dest);
}

void   move_down(int player)
{
    char    dest;

    dest = get_map()[get_pl_y(player) + 1][get_pl_x(player)];
    if (dest == ' ' || dest == KEY_RANDOMIZER)
    {
        if (dest == KEY_RANDOMIZER)
            rand_keys();
        move_player_to(player, get_pl_x(player), get_pl_y(player) + 1);
        unset_goal(player);
    }
    check_end_level(player, dest);
}

void   move_left(int player)
{
    char    dest;

    dest = get_map()[get_pl_y(player)][get_pl_x(player) - 1];
    if (dest == ' ' || dest == KEY_RANDOMIZER)
    {
        if (dest == KEY_RANDOMIZER)
            rand_keys();
        move_player_to(player, get_pl_x(player) - 1, get_pl_y(player));
        unset_goal(player);
    }
    check_end_level(player, dest);
}

void   move_right(int player)
{
    char    dest;

    dest = get_map()[get_pl_y(player)][get_pl_x(player) + 1];
    if (dest == ' ' || dest == KEY_RANDOMIZER)
    {
        if (dest == KEY_RANDOMIZER)
            rand_keys();
        move_player_to(player, get_pl_x(player) + 1, get_pl_y(player));
        unset_goal(player);
    }
    check_end_level(player, dest);
}

void    check_end_level(int player, char dest)
{
    if (player == PLAYER_ONE && dest == PLAYER_ONE_GATE
        || player == PLAYER_TWO && dest == PLAYER_TWO_GATE)
    {
        if(set_goal(player))
            ft_exit();
    }
}
