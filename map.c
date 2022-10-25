#include "headers/map.h"

void	free_map(void);
short 	contains_player(int line);
void print_player_line(char *line);
////////////////

static char **map_handler(char **new_map, int flag)
{
	static char **map;

	if (flag == e_EDIT_MAP)
	{
		if (map)
			free_map();
		map = new_map;
	}
	else if (flag == e_GET_MAP)
		return (map);
	return (NULL);
}


char	**get_map(void)
{
	return (map_handler(NULL, e_GET_MAP));
}

void	edit_map(char **new_map)
{
	map_handler(new_map, e_EDIT_MAP);
}

void	edit_map_xy(char edit, int x, int y)
{
	get_map()[y][x] = edit;
}

void 	init_map(void)
{
	level1();
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
		if (contains_player(i) == TRUE)
			print_player_line(map[i]);
		else
			printf("%s\n", map[i]);
		++i;
	}
}

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
