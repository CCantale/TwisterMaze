#ifndef LEVELS_H
# define LEVELS_H

# include "common.h"

void	edit_map(char **new_map);
char	**ft_split(char *str);
void    set_pl_gate(int player, int line);
void    set_new_randomizer(int pos);

#endif
