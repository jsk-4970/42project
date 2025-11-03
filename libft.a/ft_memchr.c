/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:05:03 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/31 21:41:14 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;
	unsigned int	uc;
	size_t			m;

	uc = (unsigned int)c;
	uc %= 256;
	us = (unsigned char *)s;
	m = 0;
	while (m < n)
	{
		if (us[m] == uc)
			return (&us[m]);
		m++;
	}
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>
//
// int main(void)
//{
//	char str[] = "Hello, World!";
//	char *result = memchr(str, 'W', 13);
//	if (result)
//		printf("Found 'W' at: %s\n", result);
//	else
//		printf("'W' not found\n");
//
//	result = memchr(str, 'z', 13);
//	if (result)
//		printf("Found 'z' at: %s\n", result);
//	else
//		printf("'z' not found\n");
//	return (0);
//}
