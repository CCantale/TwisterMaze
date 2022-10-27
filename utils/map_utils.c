#include "..\headers\utils\map_utils.h"

short contains_special(int line)
{
	return (
		line == get_pl_y(PLAYER_ONE)
		|| line == get_pl_y(PLAYER_TWO)
		|| line == pl_gate_pos(PLAYER_ONE)
		|| line == pl_gate_pos(PLAYER_TWO)
		);
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
			printf(ENDCOLOR);
		}
		else if (line[i] == PLAYER_ONE_GATE || line[i] == PLAYER_TWO_GATE)
		{
			if (line[i] == PLAYER_ONE_GATE)
				printf(CYAN);
			else
				printf(YELLOW);
			write(1, "=", 1);
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
}

void	free_map(void)
{
	int		i;
	char	**map;

	i = 0;
	while (map[i])
	{
		ft_free(map[i]);
		++i;
	}
	ft_free(map);
}
