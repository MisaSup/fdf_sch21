/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:57:08 by wcarlos           #+#    #+#             */
/*   Updated: 2022/01/13 13:50:48 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_mlx(t_fdf *fdf, t_img_data *img)
{
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, 1920, 1536, "FDF");
	img->img = mlx_new_image(fdf->mlx, 1920, 1536);
	img->addr = mlx_get_data_addr
		(img->img, &img->bits_per_px, &img->line_len, &img->endian);
	fdf->img_p = img;
}

int	key_hook(int keycode, t_fdf *fdf)
{
	(void)fdf;
	if (keycode == 53)
	{
		write(1, "Exit..\n", 7);
		free_matrix(fdf);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_fdf		fdf;
	t_img_data	img;

	if (argc == 2)
	{
		get_data((char *)argv[1], &fdf);
		set_mlx(&fdf, &img);
		drawmap(&fdf);
		mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, img.img, 10, 10);
		mlx_key_hook(fdf.mlx_win, key_hook, &fdf);
		mlx_loop(fdf.mlx);
	}
	else
		errmes(0, &fdf);
	return (0);
}
