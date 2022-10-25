#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <unistd.h>
# include "common.h"
# include "colors.h"

void    level1(void);
void	*ft_malloc(size_t size);
void	ft_free(void *ptr);
int get_pl_y(int player);

enum	e_map
{
	e_EDIT_MAP,
	e_GET_MAP
};

#endif
