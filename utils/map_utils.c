#include "..\headers\utils\map_utils.h"

short contains_player(int line)
{
	if (line == get_pl_y(PLAYER_ONE) || line == get_pl_y(PLAYER_TWO))
		return (TRUE);
	return (FALSE);
}

void print_player_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == PLAYER_ONE_CHAR)
		{
			printf(CYAN);
			write(1, "@", 1);
			printf(ENDCOLOR);
		}
		else if (line[i] == PLAYER_TWO_CHAR)
		{
			printf(YELLOW);
			write(1, "@", 1);
			printf(ENDCOLOR);
		}
		else
		{
			write(1, &line[i], 1);
		}
		++i;
	}
	write(1, "\n", 1);
}
