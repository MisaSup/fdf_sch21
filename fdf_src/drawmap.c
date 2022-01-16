/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:10:11 by wcarlos           #+#    #+#             */
/*   Updated: 2022/01/13 13:56:27 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	*get_coords(t_fdf *fdf, int x, int y, char axis)
{
	float	*answ;

	answ = (float *)malloc(sizeof(float) * 7);
	if (!answ)
		errmes(3, fdf);
	answ[0] = x;
	answ[1] = y;
	if (axis == 'x')
	{
		answ[2] = x + 1;
		answ[3] = y;
	}
	else if (axis == 'y')
	{
		answ[2] = x;
		answ[3] = y + 1;
	}
	answ[4] = fdf->z_mtrx[(int)answ[1]][(int)answ[0]][0];
	answ[5] = fdf->z_mtrx[(int)answ[3]][(int)answ[2]][0];
	answ[6] = fdf->z_mtrx[(int)answ[1]][(int)answ[0]][1];
	return (answ);
}

void	drawmap(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	while (y < fdf->y)
	{
		x = 0;
		while (x < fdf->x)
		{
			if (x < fdf->x - 1)
				drawline(fdf, get_coords(fdf, x, y, 'x'));
			if (y < fdf->y - 1)
				drawline(fdf, get_coords(fdf, x, y, 'y'));
			x++;
		}
		y++;
	}
}

void	free_matrix(t_fdf *fdf)
{
	int	i;
	int	k;

	i = fdf->y;
	while (i >= 0)
	{
		k = fdf->x;
		while (k >= 0)
		{
			if (fdf->z_mtrx[i][k])
				free(fdf->z_mtrx[i][k]);
			k--;
		}
		if (fdf->z_mtrx[i])
			free(fdf->z_mtrx[i]);
		i--;
	}
	if (fdf->z_mtrx)
		free(fdf->z_mtrx);
}
