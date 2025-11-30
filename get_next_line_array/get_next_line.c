/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:04:08 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/30 19:05:10 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <sys/types.h>

//size_t	ft_strlen(const char *str)
//
//{
//	size_t	len;
//
//	if (str == NULL)
//		return (0);
//	len = 0;
//	while (str[len])
//		len++;
//	return (len);
//}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	n;

	slen = BUFSIZE;
	dlen = dstsize;
	n = 0;
	if (dstsize <= dlen)
		return (dstsize + slen);
	while (n < dstsize - dlen - 1 && src[n])
	{
		dst[n + dlen] = src[n];
		n++;
	}
	dst[dstsize] = '\0';
	return (dlen + slen);
}

//get file and write the contents to buf until end of file
//if read() fails, return NULL;
char	*ft_getfile(int fd,  char *tmp_stash)
{
	ssize_t		ret_read;
	char		*buf;
	int			i;

	buf = NULL;
	i = 0;
	ret_read = 1;
	while (ret_read != 0)
	{
		free(buf);
		buf = malloc(BUFSIZE);
		ret_read = read(fd, buf, BUFSIZE);
//		printf("index:%d", i);
//		write(1, buf, BUFSIZE);
//		printf("\n");
		if (ret_read == -1)
			return (NULL);
		free(tmp_stash);
		i++;
		tmp_stash = malloc(BUFSIZE * i + 1);
		ft_strlcat(tmp_stash, buf, BUFSIZE * i + 1);
		write(1, tmp_stash, BUFSIZE * i);
	}
	free(buf);
	return (tmp_stash);
}

//char	*ft_extract_line(char *tmp_stash)
//{
//	char	*line;
//	return (line);
//}

//char	*ft_clean_stash(char *tmp_stash)
//{
//	return (tmp_stash);
//}

//char	*get_next_line(int fd)
//{
//	static char	*stash;
//	char		*line;
//
//	stash = ft_getfile(fd, stash);
//	line = ft_extract_line(stash);
//	stash = ft_clean_stash(stash);
//	return (line);
//}

int main(void)
{
	int	fd;
	char *tmp_stash = NULL;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (printf("file could not open\n"), 1);
	ft_getfile(fd, tmp_stash);
	printf("res of ft_getfile:%s\n", tmp_stash);

}
