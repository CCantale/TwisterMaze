#ifndef TIME_H
# define TIME_H

# include <windows.h>
# include "common.h"
# include "utils/memory_utils.h"
# include "utils/map_utils.h"

bool	one_second_has_passed(void);
void	init_timer(void);
void	update_timer(void);

#endif
