#ifndef MAP_H
# define MAP_H

# include "common.h"
# include "colors.h"

void    level1(void);
void	print_map(void);
void	free_map(void);

enum	e_map
{
	e_EDIT_MAP,
	e_GET_MAP
};

#endif
