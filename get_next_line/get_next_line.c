/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:36:34 by aburi             #+#    #+#             */
/*   Updated: 2025/11/28 22:11:43 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//return the length to newline
//int		len_to_newline(char *buf)
//{
//	int	ret;
//
//	ret = 0;
//	return (ret);
//}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	c %= 256;
	tmp = (char *)s;
	if (c == 0)
		return (tmp + ft_strlen(s));
	while (*tmp)
	{
		if (*tmp == c)
			return (tmp);
		tmp++;
	}
	return (NULL);
}

//the func to duplicate buf to list(maybe by '\n') and enter NULL to next
t_list	*append(t_list *list, char *buf)
{
	static t_list	*new_node;
	int				len;

	len = len_to_newline(buf);
	new_node = malloc(sizeof(t_list));
	new_node -> content = buf;
	new_node -> next = NULL;
	while (len < BUFSIZE)
	{

	}
	return (new_node);
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

char	*get_next_line(int fd)
{
	static t_list	*list;
	static t_list	*new_node;
	char			*buf;
	int				read_ret;

	buf = malloc(BUFSIZE + 1);
	read_ret = 1;
	while (ft_strchr(buf, '\n') && buf != 0)
	{
		read_ret = read(fd, buf, BUFSIZE);
		if (read_ret == -1)
		{
			//handle error somehow
		}
		buf[BUFSIZE] = '\0';
		append(list, buf);
		list -> content = ft_strjoin(list -> content, buf);
	}
	free(buf);
	return (new_node -> content);
}

