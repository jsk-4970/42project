/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:01:58 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/20 17:13:16 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_next_line(char *str)
{
	
}

char	*getstr(int fd)
{
	static char buf[BUFSIZE];
	static char *bufp;
	static int n;

	if (n == 0)
	{
		n = read(fd, buf, BUFSIZE);
		bufp = buf;
	}
	if (--n >= 0)
		return (bufp++);
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	struct s_list	*contents;

	if (contents == NULL)	
		return (NULL);
	if (find_next_line(contents))	
		
}

int main(void)
{
	int fd;
	int c;
	char *res;

	fd = open("text.txt", O_RDONLY);
	printf("fd:%d\n", fd);
	while (1)
	{
		c = ft_getstr(fd);
		if (c == EOF)
			break;
		printf("%c", c);
	}
//	while (res)
//	{
//		res = get_next_line(fd);
//		printf("%s\n", res);
//	}
	close (fd);
	return (0);
}
