/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:02:55 by wcarlos           #+#    #+#             */
/*   Updated: 2022/01/12 13:03:24 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_zoom(t_fdf *fdf)
{
	int	i;

	if (fdf->y < fdf->x)
		i = fdf->x;
	else
		i = fdf->y;
	if (i < 31)
		fdf->zoom = 30;
	else if (i >= 31 && i <= 50)
		fdf->zoom = 15;
	else if (i >= 51 && i <= 110)
		fdf->zoom = 10;
	else if (i >= 111 && i <= 250)
		fdf->zoom = 3;
	else if (i > 250)
		fdf->zoom = 2;
}

static void	mult_z(t_fdf *fdf)
{
	if (fdf->y < 20)
		fdf->mult_z = 3;
	else if (fdf->y >= 20 && fdf->y < 50)
		fdf->mult_z = 10;
	else if (fdf->y >= 50)
		fdf->mult_z = 3;
}

static void	set_shift(t_fdf *fdf)
{
	if (fdf->y < 25)
		fdf->shift_y = fdf->y * 35;
	else if (fdf->y > 25 && fdf->y < 50)
		fdf->shift_y = fdf->y * 10;
	else if (fdf->y < 250)
		fdf->shift_y = fdf->y * 4 + 100;
	else
		fdf->shift_y = fdf->y / 2;
	if (fdf->x < 250)
		fdf->shift_x = 1920 / 2;
	else
		fdf->shift_x = (1920 / 3) + 200;
}

void	display_settings(t_fdf *fdf)
{
	mult_z(fdf);
	set_zoom(fdf);
	set_shift(fdf);
}
