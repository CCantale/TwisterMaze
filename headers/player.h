#ifndef PLAYER_H
# define PLAYER_H

# include "common.h"

typedef struct  s_player
{
    int x;
    int y;
}   t_player;

enum
{
    e_CHANGE,
    e_GET_X,
    e_GET_Y,
    e_EXIT
};

void	edit_map_xy(char edit, int x, int y);
void	ft_free(void *ptr);
void    print_map(void);

#endif
