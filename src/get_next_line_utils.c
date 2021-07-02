/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:58:33 by rvalton           #+#    #+#             */
/*   Updated: 2021/07/02 06:07:46 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_init(void)
{
	char	*tmp;

	tmp = malloc(sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	return (tmp);
}

int	is_endl(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] == '\0' && i < 4096)
		i++;
	while (buf[i] != '\n' && i < 4096)
		i++;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

static void	get_fill(char *buf, char *tmp, int i)
{
	int	j;

	j = 0;
	while (buf[j] == '\0' && j < 4096)
		j++;
	while (buf[j] != '\n' && j < 4096)
	{
		tmp[i] = buf[j];
		buf[j] = '\0';
		i++;
		j++;
	}
	if (buf[j] == '\n')
		buf[j] = '\0';
	tmp[i] = '\0';
}

char	*get_realloc(char *buf, char **line)
{
	int		i;
	int		n;
	int		j;
	char	*tmp;

	i = 0;
	while (line[0][i])
		i++;
	j = 0;
	while (buf[j] == '\0' && j < 4096)
		j++;
	n = 0;
	while (buf[j + n] != '\n' && (j + n) < 4096)
		n++;
	tmp = malloc(sizeof(char) * (i + n + 3));
	if (!tmp)
		return (NULL);
	tmp[i + n + 2] = '\0';
	j = -1;
	while (line[0][++j])
		tmp[j] = line[0][j];
	get_fill(buf, tmp, i);
	free(line[0]);
	return (tmp);
}
