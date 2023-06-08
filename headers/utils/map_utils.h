#ifndef MAP_UTILS_H
# define MAP_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <windows.h>
# include "..\common.h"
# include "..\colors.h"

void	gotoxy(int x, int y);
int     get_pl_y(int player);
int     pl_gate_pos(int player);
void    ft_free(void *ptr);
char	**get_map(void);
int     get_rand_pos(void);
int		is_randomizer(int line);

#endif
