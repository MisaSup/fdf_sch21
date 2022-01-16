/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:01:30 by wcarlos           #+#    #+#             */
/*   Updated: 2022/01/12 13:01:39 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	get_num(char c)
{
	int	res;

	res = 0;
	if (c >= '0' && c <= '9')
		return (res + (c - '0'));
	if ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
		return (20 - (75 - ft_toupper(c)));
	return (res);
}

static int	get_dec(char *s, int i)
{	
	if (ft_strlen(s) >= 2 && i < 8)
		return ((get_num(s[0]) * 16) + (get_num(s[1]) * 1));
	return (0);
}

static int	get_i(char *s, int *answ)
{
	if (ft_strlen(s) == 9)
		return (create_trgb(0, answ[0], answ[1], answ[2]));
	else if (ft_strlen(s) == 7)
		return (create_trgb(0, 0, answ[0], answ[1]));
	return (create_trgb(0, 0, 0, answ[0]));
}

int	get_color(char *str)
{
	int	*answ;
	int	i;
	int	k;

	if (!str || ft_strlen(str) < 5)
		return (create_trgb(0, 255, 255, 255));
	answ = (int *)malloc(sizeof(int) * 3);
	if (!answ)
		return (create_trgb(0, 255, 255, 255));
	i = 3;
	k = 0;
	while (i <= 7 && k < 3)
	{
		answ[k] = get_dec(str + i, ft_strlen(str) - i);
		i += 2;
		k++;
	}
	i = get_i(str, answ);
	free(answ);
	return (i);
}
