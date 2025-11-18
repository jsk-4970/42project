/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:03:04 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/17 13:48:08 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getc(int fd)
{
	static char buf[BUFSIZE];
	static char *bufp;
	static int n;

	if (n == 0)
	{
		n = read(fd, buf, sizeof(0));
		bufp = buf;
	}
	if (--n >= 0)
		return ((unsigned char)*bufp++);
	else
		return (EOF);
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
