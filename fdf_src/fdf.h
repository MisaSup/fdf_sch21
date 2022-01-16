/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:51:51 by wcarlos           #+#    #+#             */
/*   Updated: 2022/01/12 12:54:06 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <sys/stat.h> 
# include <fcntl.h>
# include <stdio.h>
# include "../gnl/get_next_line.h"
# include <string.h>
# include <errno.h>
# define FDF_H

typedef struct Image
{
	void	*img;
	char	*addr;
	int		bits_per_px;
	int		line_len;
	int		endian;
}	t_img_data;

typedef struct Main_fdf
{
	void		*mlx;
	void		*mlx_win;
	t_img_data	*img_p;
	int			x;
	int			y;
	int			***z_mtrx;
	int			mult_z;
	int			zoom;
	int			shift_x;
	int			shift_y;
}	t_fdf;

int		ft_atoi(const char *str);
char	**my_split(const char *s, char c);
int		ft_toupper(int ch);
int		get_color(char *str);
void	get_data(char *filename, t_fdf *data);
void	display_settings(t_fdf *fdf);
void	get_z(char *filename, t_fdf *data);
void	drawline(t_fdf *fdf, float *var);
void	drawmap(t_fdf *fdf);
void	set_disp_settings(t_fdf *fdf, float *var, float *y_st, float *x_st);
void	free_matrix(t_fdf *fdf);
void	errmes(int n, t_fdf *fdf);
#endif
