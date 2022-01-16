/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:50:46 by wcarlos           #+#    #+#             */
/*   Updated: 2021/11/10 15:51:02 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;
	int			i;

	if (!ft_strchr(str, '\n'))
		str = get_str_w_n(fd, str, &i);
	if (!str || str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	result = ft_strdup(str, count_n(str, &i));
	str = get_str_after_n(str, &i);
	if (!i)
	{
		free(str);
		str = NULL;
	}
	return (result);
}

char	*get_str_w_n(int fd, char *str, int *i)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (1 + 1));
	if (!tmp)
		return (NULL);
	*i = 1;
	while (*i && !ft_strchr(str, '\n') && *i != -1)
	{
		*i = read(fd, tmp, 1);
		if (*i != 0 && *i != -1)
		{
			tmp[*i] = '\0';
			if (!str)
				str = ft_strdup(tmp, ft_strlen(tmp));
			else
				str = ft_strjoin_n_free(str, tmp);
		}
	}
	free(tmp);
	if ((*i == 0 && !str) || *i == -1 || !str)
		return (NULL);
	return (str);
}

int	count_n(char *str, int *end)
{
	int	i;

	if (!*end)
		return (ft_strlen(str));
	i = 0;
	if (str)
	{
		while (str[i] != '\n')
			i++;
		return (i + 1);
	}
	return (0);
}

char	*get_str_after_n(char *str, int *i)
{
	char	*answ;
	int		len;

	if (!*i)
		return (str);
	len = ft_strlen((ft_strchr(str, '\n') + 1)) + 1;
	if (str)
	{
		answ = malloc(sizeof(char) * len);
		if (!answ)
			return (NULL);
		ft_memset(answ, 0, len);
		answ[len - 1] = '\0';
		ft_strlcat(answ, (ft_strchr(str, '\n') + 1), len);
		free(str);
		return (answ);
	}
	return (NULL);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (b);
}
