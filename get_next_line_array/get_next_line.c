/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <aburi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:04:08 by jyamada           #+#    #+#             */
/*   Updated: 2025/12/19 15:58:56 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(int fd, char *buf)
{
	int	ret_read;

	ret_read = read(fd, buf, BUFFER_SIZE);
	if (ret_read == -1)
		return (ret_read);
	if (ret_read == 0)
		return (ret_read);
	buf[ret_read] = '\0';
	return (ret_read);
}

char	*ft_getfile(int fd, char *stash)
{
	ssize_t	ret_read;
	char	*buf;
	char	*tmp_stash;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (free(stash), NULL);
	while (1)
	{
		ret_read = ft_read(fd, buf);
		if (ret_read == -1)
			return (free(buf), free(stash), NULL);
		tmp_stash = malloc(ft_strlen(stash) + ret_read + 1);
		if (tmp_stash == NULL)
			return (free(buf), free(stash), NULL);
		tmp_stash[0] = '\0';
		ft_strlcat(tmp_stash, stash, ft_strlen(stash) + 1);
		ft_strlcat(tmp_stash, buf, ft_strlen(tmp_stash) + ret_read + 1);
		free(stash);
		if (ret_read == 0 || find_new_line(tmp_stash) != -1)
			break ;
	}
	return (free(buf), tmp_stash);
}

char	*ft_extract_line(char *tmp_stash)
{
	char	*line;
	size_t	i;
	size_t	j;

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

char	*ft_clean_stash(char *tmp_stash, size_t len_line)
{
	char	*new_line;
	size_t	len_new_line;

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

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL || find_new_line(stash) == -1)
		stash = ft_getfile(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = ft_extract_line(stash);
	if (line == NULL)
		return (free(stash), stash = NULL, NULL);
	stash = ft_clean_stash(stash, ft_strlen(line));
	return (line);
}
