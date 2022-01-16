/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xyz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:12:38 by wcarlos           #+#    #+#             */
/*   Updated: 2022/01/13 13:52:43 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_x(char *line, t_fdf *data)
{
	char	**str;

	write(1, "[I...]\n", 7);
	str = NULL;
	if (line)
		str = my_split(line, ' ');
	data->x = -1;
	while (str && str[++data->x] && line)
		free(str[data->x]);
	if (str)
		free(str);
	write(1, "[II..]\n", 7);
}

static int	gnl_ck(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	free(line);
	return (1);
}

static void	get_yx(char *filename, t_fdf *data)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDWR);
	if (fd == -1)
		errmes(1, data);
	line = get_next_line(fd);
	get_x(line, data);
	if (line)
	{
		data->y = 1;
		while (gnl_ck(fd))
				data->y++;
		free(line);
	}
	close(fd);
	if (data->x == -1)
		errmes(2, data);
}

void	get_data(char *filename, t_fdf *data)
{
	write(1, "Parsing map...\n", 15);
	write(1, "[....]\n", 7);
	get_yx(filename, data);
	display_settings(data);
	write(1, "[III.]\n", 7);
	get_z(filename, data);
	write(1, "[IIII]\n", 7);
}
