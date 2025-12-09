/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <aburi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:04:08 by jyamada           #+#    #+#             */
/*   Updated: 2025/12/09 16:37:25 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

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


//get file and write the contents to buf until end of file
//if read() fails, return NULL;
//tmp_stash is actually (static char *)stash
//new_stash is 
char	*ft_getfile(int fd,  char *stash)
{
	ssize_t		ret_read;
	char		*buf;
	char		*tmp_stash;

	ret_read = 1;
	buf = malloc(BUFSIZE + 1);
	while (ret_read != 0)
	{
		ret_read = read(fd, buf, BUFSIZE);
		if (ret_read == -1)
			return (NULL);
		buf[ret_read] = '\0';
		tmp_stash = malloc(ft_strlen(stash) + ft_strlen(buf) + 1);
		tmp_stash[0] = '\0';
		ft_strlcat(tmp_stash, stash, ft_strlen(stash) + 1);
		ft_strlcat(tmp_stash, buf, ft_strlen(stash) + ft_strlen(buf) + 1);
		free(stash);
		stash = tmp_stash;
	}
	free(buf);
	return (stash);
}

char	*ft_extract_line(char *tmp_stash)
{
	char	*line;
	int		i;

	i = 0;
	while (tmp_stash[i] != '\0' && tmp_stash[i] != '\n')
		i++;
	line = malloc(i + 1);
	line[0] = '\0';
	ft_strlcat(line, tmp_stash, i + 1);
	return (line);
}

char	*ft_clean_stash(char *tmp_stash, int len_line)
{
	char	*new_line;
	int		len_new_line;

	len_new_line = ft_strlen(tmp_stash) - len_line;
	new_line = malloc(len_new_line + 1);
	new_line[0] = '\0';
	ft_strlcat(new_line, &tmp_stash[len_line - 1], len_new_line + 1);
	return (tmp_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (stash == NULL)
		stash = ft_getfile(fd, stash);
	line = ft_extract_line(stash);
	stash = ft_clean_stash(stash, ft_strlen(line));
	return (line);
}

int main(void)
{
	int	fd;
	char *tmp_stash = NULL;
	char *line1;
	char *line2;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (printf("file could not open\n"), 1);
	tmp_stash = ft_getfile(fd, tmp_stash);
	printf("res of ft_getfile:%s\n", tmp_stash);
	line1 = ft_extract_line(tmp_stash);
	printf("res of ft_extract_line:%s\n", line1);
	line2 = ft_clean_stash(tmp_stash, ft_strlen(line1));
	printf("res of ft_clean_stash:%s", line2);
	while (get_next_line())	
	printf("res of gnl:%s", get_next_line(fd));
}
