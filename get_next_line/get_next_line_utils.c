/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:03:04 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/30 14:52:06 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//int	ft_getc(int fd)
//{
//	static char buf[BUFSIZE];
//	static char *bufp;
//	static int n;
//
//	if (n == 0)
//	{
//		n = read(fd, buf, sizeof(0));
//		bufp = buf;
//	}
//	if (--n >= 0)
//		return ((unsigned char)*bufp++);
//	else
//		return (EOF);
//}

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

//if it find '\n', return the len to '\n' but if it doesnt find '\n', return -1
int	len_to_newline(const char *s)
{
	int	len;

	len = 0;
	while (len < BUFSIZE)
	{
		if (s[len] == '\n')
			return (len);
		len++;
	}
	return (-1);
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
	dst[n + dlen] = '\0';
	return (dlen + slen);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		srcsize;
	size_t	i;

	i = 0;
	srcsize = ft_strlen(src);
	if (dstsize == 0)
		return (srcsize);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		len1;
	size_t		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len1 + 1);
	ft_strlcat(res, s2, len1 + len2 + 1);
	return (res);
}

//int main(void)
//{
//	int fd;
//	int c;
//
//	fd = open("text.txt", O_RDONLY);
//	printf("fd:%d\n", fd);
//	while (1)
//	{
//		c = ft_getc(fd);
//		if (c == EOF)
//			break;
//		printf("%c", c);
//	}
//	close (fd);
//	return (0);
//}
