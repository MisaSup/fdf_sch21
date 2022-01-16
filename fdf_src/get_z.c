/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:14:47 by wcarlos           #+#    #+#             */
/*   Updated: 2022/01/13 13:52:09 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	allocation(t_fdf *data)
{
	int	i;
	int	k;

	data->z_mtrx = (int ***)malloc(sizeof(int) * (data->y + 1) * (data->x + 1));
	if (!data->z_mtrx)
		errmes(3, data);
	i = 0;
	while (i <= data->y)
	{
		data->z_mtrx[i] = (int **)malloc(sizeof(int) * (data->x + 1) * 2);
		k = 0;
		while (k <= data->x)
		{
			data->z_mtrx[i][k] = (int *)malloc(sizeof(int) * 2);
			if (!data->z_mtrx[i][k])
				errmes(3, data);
			k++;
		}
		if (!data->z_mtrx[i])
			errmes(3, data);
		i++;
	}
}

static void	fill_matrx(char *line, int ***z, int index)
{
	char	**str;
	int		i;

	str = my_split(line, ' ');
	i = 0;
	if (str)
	{
		while (str[i])
		{
			z[index][i][0] = ft_atoi(str[i]);
			z[index][i][1] = get_color(ft_strchr(str[i], ','));
			i++;
		}
		while (--i >= 0)
			free(str[i]);
		free(line);
		free(str);
	}
	else
		exit(EXIT_FAILURE);
}

static void	fill_matrx_large(char *line, int ***z, int index, t_fdf *data)
{
	char	**str;
	int		i;
	int		k;

	str = my_split(line, ' ');
	k = data->x;
	i = 0;
	if (str)
	{
		while (str[i])
		{
			z[index][k][0] = ft_atoi(str[i]);
			z[index][k][1] = get_color(ft_strchr(str[i], ','));
			i++;
			k--;
		}
		while (--i >= 0)
			free(str[i]);
		free(line);
		free(str);
	}
	else
		exit(EXIT_FAILURE);
}

void	get_z(char *filename, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	allocation(data);
	fd = open(filename, O_RDWR);
	if (fd == -1)
		errmes(1, data);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (data->y < 100)
			fill_matrx(line, data->z_mtrx, i);
		else
			fill_matrx_large(line, data->z_mtrx, i, data);
		line = get_next_line(fd);
		i++;
	}
	data->z_mtrx[i + 1] = NULL;
	close(fd);
}
