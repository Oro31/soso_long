#include "so_long.h"

void	ft_putstr(char *str)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (str[i] && w != -1)
	{
		w = write(1, &str[i], 1);
		i++;
	}
}
