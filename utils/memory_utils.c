#include "..\headers\utils\memory_utils.h"

void	ft_exit(void)
{
	free_map();
	exit(0);
}

void 	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_exit();
	return (ptr);
}

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
}
