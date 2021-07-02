#include "so_long.h"

static void	ft_set_rsl(int i, int j, t_rsl *rsl)
{
	rsl->w = i;
	rsl->h = j;
}

static void	ft_check_assets(t_vars *vars, t_map *monde, t_rsl *rsl)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	while (monde->map[++j])
	{
		i = -1;
		while (monde->map[j][++i])
		{
			if (monde->map[j][i] == 'C')
				monde->ncol++;
			else if (monde->map[j][i] == 'E')
			{
				monde->posxe = i;
				monde->posye = j;
			}
			else if (monde->map[j][i] == 'P')
			{
				vars->ply.posx = i;
				vars->ply.posy = j;
			}
		}
	}
	ft_set_rsl(i, j, rsl);
}

int	ft_init_world(t_vars *vars, t_map *monde)
{
	t_rsl	rsl;

	ft_check_assets(vars, monde, &rsl);
	vars->rsl.w = rsl.w * 24;
	vars->rsl.h = rsl.h * 24;
	if (monde->ncol == 0 || monde->posxe < 0 || vars->ply.posx < 0)
		return (0);
	return (1);
}
