#include "headers/game.h"

void   start_game(void)
{
    int c;

    while (1)
    {
        c = getch();
        move_player_one(c);
        move_player_two(c);
        if (c == 'q')
            ft_exit();
    }
}
