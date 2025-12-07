/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <aburi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:04:08 by jyamada           #+#    #+#             */
/*   Updated: 2025/12/06 20:54:20 by aburi            ###   ########.fr       */
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
	dst[dstsize] = '\0';
	return (dlen + slen);
}


//void	*ft_memcpy(void *dest, const void *src, size_t n)
//{
//	size_t			i;
//	unsigned char	*udest;
//	unsigned char	*usrc;
//
//	i = 0;
//	udest = (unsigned char *)dest;
//	usrc = (unsigned char *)src;
//	if (n == 0 || (udest == NULL && usrc == NULL))
//		return (udest);
//	while (i < n)
//	{
//		udest[i] = usrc[i];
//		i++;
//	}
//	return (udest);
//}

//get file and write the contents to buf until end of file
//if read() fails, return NULL;
//tmp_stash is actually (static char *)stash
//new_stash is 
char	*ft_getfile(int fd,  char *stash)
{
	ssize_t		ret_read;
	char		*buf;
	char		*tmp_stash;
	int			i;

	i = 0;
	ret_read = 1;
	while (ret_read != 0)
	{
		buf = malloc(BUFSIZE + 1);
		ret_read = read(fd, buf, BUFSIZE);
		if (ret_read == -1)
			return (NULL);
		buf[ret_read] = '\0';
		i++;
		tmp_stash = malloc(BUFSIZE * i + 1);
		tmp_stash[0] = '\0';
		if (stash != NULL)
		{
			ft_strlcat(tmp_stash, stash, BUFSIZE * i + 1);
			free(stash);
		}
		ft_strlcat(tmp_stash, buf, BUFSIZE * i + 1);
		stash = tmp_stash;
		free(buf);
	}
	return (stash);
}

// char	*ft_extract_line(char *tmp_stash)
// {
// 	char	*line;
// 	return (line);
// }

//char	*ft_clean_stash(char *tmp_stash)
//{
//	return (tmp_stash);
//}

//char	*get_next_line(int fd)
//{
//	static char	*stash;
//	char		*line;
//
//	if (stash == NULL)
//		stash = ft_getfile(fd, stash);
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
