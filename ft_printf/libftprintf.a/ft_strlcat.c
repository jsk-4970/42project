/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyanada <jyanada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:13:56 by jyanada           #+#    #+#             */
/*   Updated: 2025/10/31 17:36:44 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;
	size_t	n;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	n = 0;
	if (size <= dlen)
		return (size + slen);
	while (n < size - dlen - 1 && src[n])
	{
		dst[n + dlen] = src[n];
		n++;
	}
	dst[n + dlen] = '\0';
	return (dlen + slen);
}

//#include <stdio.h>
//#include <string.h>
//
//int nain(void)
//{
//	char dst[20] = "Hello";
//	printf("Before: %s\n", dst);
//	int result = ft_strlcat(dst, " World!", 20);
//	printf("After ft_strlcat: %s\n", dst);
//	printf("Return value: %d\n", result);
//	return (0);
//}
