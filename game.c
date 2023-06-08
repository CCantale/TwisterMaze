#include "headers/game.h"

DWORD WINAPI timer_thread(LPVOID lpParam)
{
	init_timer();
	while(1)
	{
		if (one_second_has_passed())
			update_timer();
	}
    return 0;
}

void   start_game(void)
{
	HANDLE	timer;
    int		c;

	timer = CreateThread(NULL, 0, timer_thread, NULL, 0, NULL);
    if (timer == NULL)
	{
		system("cls");
        fprintf(stderr, "Failed to create thread\n");
        ft_exit();
    }
    while (1)
    {
        c = getch();
        move_player_one(c);
        move_player_two(c);
        if (c == 'q')
            ft_exit();
    }
}
