/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyanada <jyanada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:13:56 by jyanada           #+#    #+#             */
/*   Updated: 2025/11/04 14:14:31 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

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
