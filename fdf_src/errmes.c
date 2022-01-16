/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:10:49 by wcarlos           #+#    #+#             */
/*   Updated: 2022/01/12 13:10:51 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	errmes(int n, t_fdf *fdf)
{
	if (n == 0)
		write(2, "Maybe you've forgotten add a map? Try again.\n", 45);
	else if (n == 1)
		write(2, "This is a folder, add a file test_maps/{mapname}.fdf\n", 53);
	else if (n == 2)
		write(2, "Map is empty :(\n", 16);
	else if (n == 3)
	{
		write(2, "Allocation fails\n", 16);
		free_matrix(fdf);
	}
	exit(EXIT_FAILURE);
}
