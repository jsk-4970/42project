/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:10:01 by aburi             #+#    #+#             */
/*   Updated: 2025/10/31 21:55:17 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	int		srcsize;
	size_t	i;

	i = 0;
	srcsize = ft_strlen(src);
	if (dstsize == 0)
		return (srcsize);
	while (src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srcsize);
}

//#include <stdio.h>
//
// int main(void)
//{
//	char src[] = "hello 42";
//	char dest[20];
//	int result;
//
//	printf("src = %s\n", src);
//	result = ft_strlcpy(dest, src, 5);
//	printf("dest = %s\n", dest);
//	printf("return (value = %d\n", result));
//
//	result = ft_strlcpy(dest, src, 20);
//	printf("dest (full copy) = %s\n", dest);
//	printf("return (value = %d\n", result));
//	return (0);
//}
