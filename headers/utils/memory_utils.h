#ifndef MEMORY_UTILS_H
# define MEMORY_UTILS_H

# include <stdlib.h>
# include "..\common.h"
void	ft_free(void *ptr);

void	free_map(void);
void	ft_exit(void);
void 	*ft_malloc(size_t size);

#endif
