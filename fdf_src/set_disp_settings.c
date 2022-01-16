/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_disp_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:05:47 by wcarlos           #+#    #+#             */
/*   Updated: 2022/01/12 14:17:58 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	module(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

static float	which_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	projection(float *x, float *y, int z, t_fdf *fdf)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(1) - (z * fdf->mult_z);
}

void	set_disp_settings(t_fdf *fdf, float *var, float *y_st, float *x_st)
{
	int		i;
	float	max;

	(void)fdf;
	i = -1;
	while (++i < 4)
		var[i] *= fdf->zoom;
	projection(&var[0], &var[1], var[4], fdf);
	projection(&var[2], &var[3], var[5], fdf);
	var[0] += fdf->shift_x;
	var[1] += fdf->shift_y;
	var[2] += fdf->shift_x;
	var[3] += fdf->shift_y;
	*x_st = var[2] - var[0];
	*y_st = var[3] - var[1];
	max = which_max(module(*x_st), module(*y_st));
	*x_st /= max;
	*y_st /= max;
}
