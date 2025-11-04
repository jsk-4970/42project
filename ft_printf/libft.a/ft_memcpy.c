/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:57:13 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/31 21:41:02 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*udest;
	unsigned char	*usrc;

	i = 0;
	udest = (unsigned char *)dest;
	usrc = (unsigned char *)src;
	if (n == 0 || usrc == NULL)
		return (udest);
	while (i < n)
	{
		udest[i] = usrc[i];
		i++;
	}
	return (udest);
}
//#include <stdio.h>
//#include <string.h>
//
// int main(void)
//{
//	char src[] = "hello 42";
//	char dest[20];
//	printf("src: %s\n", src);
//	ft_memcpy(dest, src, 8);
//	dest[8] = '\0';
//	printf("dest after ft_memcpy: %s\n", dest);
//
//	char data[] = "ABCDEFGHIJ";
//	printf("\nBefore: %s\n", data);
//	ft_memcpy(data + 2, data, 5);
//	printf("After ft_memcpy(data+2, data, 5): %s\n", data);
//	return (0);
//}
