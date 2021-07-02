#include "so_long.h"

void	ft_error(int e)
{
	ft_putstr("Error\n");
	if (e == 1)
		perror("Initialisation before parsing failed");
	else if (e == 2)
		perror("Opening file failed");
	else if (e == 3)
	{
		ft_putstr("Map is not playable: Map must have at least 1 exit (E),");
		ft_putstr("1 collectible (C) and 1 starting position (P)\n");
	}
	else if (e == 4)
		perror("Loading xpm files failed");
	else if (e == 5)
	{
		ft_putstr("Map contain bad characters: Map can only be composed of ");
		ft_putstr("5 possibles characters, 0 (empty space), 1 (walls), C (co");
		ft_putstr("llectible) E (map exit) and P (player starting position)\n");
	}
	else if (e == 6)
		ft_putstr("Map is not rectangular\n");
	else if (e == 7)
		ft_putstr("Map is not surrounded by walls\n");
}
