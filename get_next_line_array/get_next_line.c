/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:04:08 by jyamada           #+#    #+#             */
/*   Updated: 2025/12/18 15:37:28 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)

{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	n;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	n = 0;
	if (dstsize <= dlen)
		return (dstsize + slen);
	while (n < dstsize - dlen - 1 && src[n])
	{
		dst[n + dlen] = src[n];
		n++;
	}
	dst[dlen + n] = '\0';
	return (dlen + slen);
}

int	find_new_line(char *str)
{
	int		i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_getfile(int fd, char *stash)
{
	ssize_t	ret_read;
	char	*buf;
	char	*tmp_stash;

	ret_read = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	while (1)
	{
		ret_read = read(fd, buf, BUFFER_SIZE);
		if (ret_read <= 0)
			return (free(buf), stash);
		buf[ret_read] = '\0';
		tmp_stash = malloc(ft_strlen(stash) + ret_read + 1);
		if (tmp_stash == NULL)
			return (NULL);
		tmp_stash[0] = '\0';
		ft_strlcat(tmp_stash, stash, ft_strlen(stash) + 1);
		ft_strlcat(tmp_stash, buf, ft_strlen(tmp_stash) + ret_read + 1);
		free(stash);
		stash = tmp_stash;
		if (ret_read == 0 || find_new_line(tmp_stash) != -1)
			break ;
	}
	return (free(buf), stash);
}

char	*ft_extract_line(char *tmp_stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (tmp_stash[i] != '\0' && tmp_stash[i] != '\n')
		i++;
	if (tmp_stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (line == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = tmp_stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_clean_stash(char *tmp_stash, int len_line)
{
	char	*new_line;
	int		len_new_line;

	len_new_line = ft_strlen(tmp_stash) - len_line;
	if (len_new_line == 0)
		return (free(tmp_stash), NULL);
	new_line = malloc(len_new_line + 1);
	if (new_line == NULL)
		return (free(tmp_stash), NULL);
	new_line[0] = '\0';
	ft_strlcat(new_line, &tmp_stash[len_line], len_new_line + 1);
	free(tmp_stash);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd == -1)
		return (NULL);
	if (stash == NULL || find_new_line(stash) == -1)
		stash = ft_getfile(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = ft_extract_line(stash);
	stash = ft_clean_stash(stash, ft_strlen(line));
	return (line);
}
