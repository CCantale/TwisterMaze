#include "..\headers\utils\map_utils.h"

void	gotoxy(int x, int y)
{
	COORD	coord;

	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

short contains_special(int line)
{
	return (
			line == get_pl_y(PLAYER_ONE)
			|| line == get_pl_y(PLAYER_TWO)
			|| line == pl_gate_pos(PLAYER_ONE)
			|| line == pl_gate_pos(PLAYER_TWO)
			|| is_randomizer(line)
		);
}

int	is_randomizer(int line)
{
	int	randomizers_pos;

	randomizers_pos = get_rand_pos();
	while (randomizers_pos)
	{
		if (randomizers_pos % 100 == line)
			return (TRUE);
		randomizers_pos /= 100;
	}
	return (FALSE);
}

void print_special_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == PLAYER_ONE_CHAR || line[i] == PLAYER_TWO_CHAR)
		{
			if (line[i] == PLAYER_ONE_CHAR)
				printf(CYAN);
			else
				printf(YELLOW);
			write(1, "@", 1);
		}
		else if (line[i] == PLAYER_ONE_GATE || line[i] == PLAYER_TWO_GATE)
		{
			if (line[i] == PLAYER_ONE_GATE)
				printf(CYAN);
			else
				printf(YELLOW);
			write(1, "=", 1);
		}
		else if (line[i] == KEY_RANDOMIZER)
		{
			printf(RED);
			write(1, "?", 1);
		}
		else
		{
			write(1, &line[i], 1);
		}
		printf(ENDCOLOR);
		++i;
	}
	write(1, "\n", 1);
}

void	print_map(void)
{
	int		i;
	char	**map;

	system("cls");
	map = get_map();
	i = 0;
	while (map[i])
	{
		if (contains_special(i) == TRUE)
			print_special_line(map[i]);
		else
			printf("%s\n", map[i]);
		++i;
	}
	gotoxy(0, 0);
}

void	free_map(void)
{
	int		i;
	char	**map;

	map = get_map();
	i = 0;
	while (map[i])
	{
		ft_free(map[i]);
		++i;
	}
	ft_free(map);
}
