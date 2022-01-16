/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:54:16 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/10 13:29:03 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	parsenum(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		if (str[i] == '-' && (ft_strcmp(str, "-9223372036854775808") >= 0)
			&& ft_strlen(str) > 19)
			return (0);
		i++;
	}
	if (ft_strcmp(str, "9223372036854775808") >= 0
		&& (ft_strlen(str) >= 19 && str[i - 1] != '-'))
		return (-1);
	return (parsenum(&((char *)str)[i]) * sign);
}
