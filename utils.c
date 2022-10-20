#include "headers/utils.h"

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

size_t	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*alloc_string(char *str)
{
	int	i;
	char	*new_string;

	if (!str)
		return (NULL);
	new_string = ft_malloc(sizeof(char) * (str_len(str) + 1));
	i = 0;
	while (str[i])
	{
		new_string[i] = str[i];
		++i;
	}
	new_string[i] = 0;
	return (new_string);
}

char	*splitcpy(char *str, int *j)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		++i;
	*j += i + 1;
	new_str = ft_malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\n' && str[i] != 0)
	{
		new_str[i] = str[i];
		++i;
	}
	new_str[i] = 0;
	return (new_str);
}

int	split_count(char *str)
{
	int	i;
	int	lines;

	lines = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			++lines;
		++i;
	}
	return (lines);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		lines;
	char	**split;

	if (!str)
		return (NULL);
		lines = split_count(str);
	split = ft_malloc(sizeof(char *) * (lines + 1));
	split[lines] = 0;
	i = 0;
	j = 0;
	while (i < lines)
	{
		split[i] =	splitcpy(&str[j], &j);
		++i;
	}
	return (split);
}
