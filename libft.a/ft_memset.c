/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:37:53 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/25 16:44:15 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;

	cs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		cs[i] = c;
		i++;
	}
	return (cs);
}
//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char buf[16];
//	memset(buf, 'A', 10);
//	buf[10] = '\0';
//	printf("memset(buf, 'A', 10): %s\n", buf);
//
//	memset(buf, 0, 16);
//	printf("After memset(buf, 0, 16): all zeros? ");
//	int all_zero = 1;
//	for (int i = 0; i < 16; i++)
//		if (buf[i] != 0)
//			all_zero = 0;
//	printf("%s\n", all_zero ? "Yes" : "No");
//	return (0);
//}
