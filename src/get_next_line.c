/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 02:03:14 by rvalton           #+#    #+#             */
/*   Updated: 2021/07/02 06:06:46 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_next_line(int fd, char **line)
{
	int			rd_rtn_value;
	static char	buf[4096] = {0};

	if (fd < 0)
		return (-1);
	line[0] = get_init();
	if (!line[0])
		return (-1);
	while (!(is_endl(buf)))
	{
		line[0] = get_realloc(buf, line);
		if (!line[0])
			return (-1);
		rd_rtn_value = read(fd, buf, 4096);
		if (rd_rtn_value == -1)
			return (-1);
		else if (rd_rtn_value == 0)
			return (0);
	}
	if (is_endl(buf))
		line[0] = get_realloc(buf, line);
	if (!line[0])
		return (-1);
	return (1);
}
