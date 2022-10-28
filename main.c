#include "headers/main.h"

int	main(void)
{
	time_t t;

	srand((unsigned)time(&t));
	init_map();
	init_player();
	print_map();
	start_game();
	return (0);
}
