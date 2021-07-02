/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:50:28 by rvalton           #+#    #+#             */
/*   Updated: 2021/07/02 06:15:57 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_myxpm_pixelput(t_vars *vars, int x, int y)
{
	int	color;

	color = 0;
	if (vars->monde.map[y / 24][x / 24] == 'P')
	{
		x = (x % 24) + (vars->ply.xdir * 24);
		y = (y % 24) + (vars->ply.ydir * 24);
		color = ft_get_ply_xpm_pixel(&vars->ply.spr, x, y);
	}
	else if (vars->monde.map[y / 24][x / 24] == 'e')
		color = ft_get_xpm_pixel(&vars->monde.odoor, x % 24, y % 24);
	else if (vars->monde.map[y / 24][x / 24] == 'E')
		color = ft_get_xpm_pixel(&vars->monde.cdoor, x % 24, y % 24);
	else if (vars->monde.map[y / 24][x / 24] == 'C')
		color = ft_get_xpm_pixel(&vars->monde.collect, x % 24, y % 24);
	return (color);
}

int	ft_get_xpm_pixel(t_data *data, int x, int y)
{
	int	color;

	color = *((int *)data->addr + (x + y * 24));
	return (color);
}

int	ft_get_ply_xpm_pixel(t_data *data, int x, int y)
{
	int	color;

	color = *((int *)data->addr + (x + y * 48));
	return (color);
}
