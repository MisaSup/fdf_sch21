/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:54:55 by wcarlos           #+#    #+#             */
/*   Updated: 2021/11/10 16:28:19 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>

# define GET_NEXT_LINE_H

char	*get_next_line(int fd);
char	*get_str_w_n(int fd, char *str, int *i);
int		count_n(char *str, int *end);
char	*get_str_after_n(char *str, int *i);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_n_free(char *s1, char *s2);
char	*ft_strdup(const char *s1, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *b, int c, size_t len);

#endif
