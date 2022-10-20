#include "headers/map.h"

static char	*next_map_line(int line);
void	free_map(void);
// end of static declarations

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
	int	i;

	system("cls");
	i = 0;
	while (get_map()[i])
	{
		printf("%s\n", get_map()[i]);
		++i;
	}
}

void	free_map(void)
{
	int	i;

	i = 0;
	while (get_map()[i])
	{
		ft_free(get_map()[i]);
		++i;
	}
	ft_free(get_map());
}
