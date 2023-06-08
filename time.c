#include "headers/time.h"

bool	one_second_has_passed(void)
{
	static DWORD	last_time;
	DWORD			time_right_now;

	if (last_time == 0)
	{
		last_time = GetTickCount();
		return (false);
	}
	else
	{
		time_right_now = GetTickCount();
		if (time_right_now - last_time >= 1000)
		{
			last_time = time_right_now;
			return (true);
		}
		return (false);
	}
}

void	init_timer(void)
{
	gotoxy(5, 10);
	printf("50");
	gotoxy(0, 0);
}

void	update_timer(void)
{
	static short	seconds = 50;

	gotoxy(5, 10);
	seconds -= 1;
	printf("%hu ", seconds);
	gotoxy(0, 0);
	if (seconds == 0)
		ft_exit();
}
