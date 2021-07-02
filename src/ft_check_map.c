#include "so_long.h"

int	ft_lenmax_mpline(char **map)
{
	int	i;
	int	len;
	int	max;

	max = 0;
	i = 0;
	while (map[i])
	{
		len = ft_len_mpline(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static	int	ft_ischar_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = ft_len_mpline(map[i]);
		while (j > 0)
		{
			j--;
			if (!ft_ismap_member(map[i][j]))
				return (0);
		}
		i++;
	}
	return (1);
}

static	int	ft_ismap_rect(char **map)
{
	int	i;
	int	j;
	int	maxlen;

	maxlen = ft_lenmax_mpline(map);
	i = 0;
	while (map[i])
	{
		j = ft_len_mpline(map[i]);
		if (j != maxlen)
			return (0);
		i++;
	}
	return (1);
}

static	int	ft_ismap_walled(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = ft_len_mpline(map[i]) - 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j] != '1')
			return (0);
		i++;
	}
	i--;
	while (j >= 0)
	{
		if (map[0][j] != '1' || map[i][j] != '1')
			return (0);
		j--;
	}
	return (1);
}

int	ft_check_map(char **map)
{
	if (!ft_ischar_valid(map))
		return (5);
	if (!ft_ismap_rect(map))
		return (6);
	if (!ft_ismap_walled(map))
		return (7);
	return (0);
}
