/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:07:10 by wcarlos           #+#    #+#             */
/*   Updated: 2022/01/12 12:45:10 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	get_lenghts(const char *s, char c, int *arr, int len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && arr[count] != (-1))
	{
		if (s[i] != c && s[i] != '\0')
		{
			len++;
			if ((s[i + 1] == c || s[i + 1] == '\0') && len != 0)
			{
				arr[count] = len;
				count++;
				len = 0;
			}
		}
		i++;
	}
}

static int	*create_arr(const char *s, char c)
{
	int	i;
	int	count;
	int	*arr;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{	
			count++;
			if (s[i - 1] != c && count != 1)
				count--;
		}
		i++;
	}
	arr = (int *)malloc(sizeof(int) * count + 1);
	if (arr)
	{
		arr[count] = -1;
		get_lenghts(s, c, arr, 0);
	}
	return (arr);
}

static void	get_elem(int len, const char *src, char **answ, int index)
{
	int	i;

	answ[index] = (char *)malloc(sizeof(char) * len + 1);
	if (!answ[index])
	{
		while (--index >= 0)
			free(answ[index]);
		free(answ);
	}
	if (answ[index])
	{	
		i = -1;
		while (++i < len)
			answ[index][i] = src[i];
		answ[index][i] = '\0';
	}
}

static int	get_arr_len(int *arr)
{
	int	i;

	i = 0;
	while (arr && arr[i] != (-1))
		i++;
	return (i);
}

char	**my_split(const char *s, char c)
{
	char	**answ;
	int		*lenghts;
	int		i;
	int		index;

	lenghts = create_arr(s, c);
	answ = (char **)malloc(sizeof(char *) * (get_arr_len(lenghts) + 1));
	if (answ && lenghts)
	{
		i = 0;
		index = -1;
		while (lenghts[++index] != (-1) && s[i])
		{
			while (s[i] == c)
				i++;
			get_elem(lenghts[index], &s[i], answ, index);
			if (!answ[index] || !answ)
				return (NULL);
			i = i + lenghts[index];
		}
		free(lenghts);
		answ[index] = NULL;
	}
	return (answ);
}
