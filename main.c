#include "headers/main.h"

int	main(void)
{
	char	**map;

	init_map();
	init_player();
	print_map();
	start_game();
	ft_exit();
	return (0);
}
