/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:07:40 by wcarlos           #+#    #+#             */
/*   Updated: 2022/01/12 13:07:56 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_px_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_px / 8));
	*(unsigned int *)dst = color;
}

void	drawline(t_fdf *fdf, float *var)
{
	float	x_st;
	float	y_st;

	set_disp_settings(fdf, var, &y_st, &x_st);
	while (((int)var[2] - (int)var[0]) || ((int)var[3] - (int)var[1]))
	{
		ft_px_put(fdf->img_p, (int)var[0], (int)var[1], (int)var[6]);
		var[0] += x_st;
		var[1] += y_st;
		if ((!((int)var[2] - (int)var[0]) && !((int)y_st))
			|| (!((int)var[3] - (int)var[1]) && !((int)x_st)))
			break ;
	}
	// free(var);
}
