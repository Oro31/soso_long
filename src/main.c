#include "so_long.h"

int	ft_resize_hook(t_vars *vars)
{
	ft_draw(vars);
	return (1);
}

void	ft_parse_line(char *line, t_vars *vars)
{
	vars->monde.map = ft_parse_map(line, vars->monde.map);
	free(line);
	line = NULL;
}

int	ft_get_started(t_vars *vars)
{
	int	res;

	res = ft_init_world(vars, &vars->monde);
	if (!(res))
		return (3);
	res = ft_load_xpmfiles(vars);
	if (!(res))
		return (4);
	res = ft_check_map(vars->monde.map);
	if (res != 0)
		return (res);
	vars->win = mlx_new_window(vars->mlx, vars->rsl.w, vars->rsl.h,
			"./so_long");
	ft_draw(vars);
	return (1);
}

static void	ft_gnl(int fd, char **line, t_vars *vars)
{
	while (get_next_line(fd, line) > 0)
		ft_parse_line(*line, vars);
	free(*line);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		fd;
	char	*line;
	int		res;

	line = NULL;
	res = ft_init_before_parse(&vars);
	if (!(res))
		return (ft_exit(&vars, 1));
	if (argc < 2)
		return (ft_exit(&vars, 8));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_exit(&vars, 2));
	ft_gnl(fd, &line, &vars);
	close(fd);
	res = ft_get_started(&vars);
	if (res != 1)
		return (ft_exit(&vars, res));
	mlx_hook(vars.win, 3, 1L << 1, ft_key_hook, &vars);
	mlx_hook(vars.win, 33, 1L << 17, ft_redcross, &vars);
	mlx_hook(vars.win, 9, 1L << 21, ft_resize_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
