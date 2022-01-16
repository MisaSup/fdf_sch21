/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:53:19 by wcarlos           #+#    #+#             */
/*   Updated: 2021/11/10 15:53:32 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*result;
	int		i;

	if (c >= 256)
		c = c - 256;
	if (s)
	{
		result = (char *)s;
		i = 0;
		while (result[i] != '\0')
		{
			if (result[i] == c)
			{
				return (&result[i]);
			}
			i++;
		}
		if (c == '\0')
			return (&result[i]);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1, size_t size)
{
	char	*copy;
	size_t	i;

	copy = NULL;
	copy = (char *)malloc(sizeof(char) * size + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && i < size)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = ft_strlen(dst);
	result = i;
	j = 0;
	while (src[j] != '\0' && i < (dstsize - 1) && dstsize != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize < result)
		return (ft_strlen(src) + dstsize);
	return (ft_strlen(src) + result);
}

char	*ft_strjoin_n_free(char *s1, char *s2)
{
	char	*result;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = NULL;
	if (s1 && s2)
	{
		result = (char *)malloc(size * sizeof(char));
		if (result == NULL)
			return (NULL);
		ft_memset(result, 0, size);
		ft_strlcat(result, s1, size);
		ft_strlcat(result, s2, size);
		result[size - 1] = '\0';
		free(s1);
	}
	return (result);
}
