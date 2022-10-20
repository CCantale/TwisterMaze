#include "headers/game.h"

void   start_game(void)
{
    int c;

    while (1)
    {
        c = getch();
        if (c == 'w')
            move_up();
        else if (c == 's')
            move_down();
        else if (c == 'a')
            move_left();
        else if (c == 'd')
            move_right();
        else if (c == 'q')
            ft_exit();
    }
}
