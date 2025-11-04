/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:32:58 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/29 22:46:49 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			m;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	m = 0;
	if (n == 0)
		return (0);
	while (m < n)
	{
		if (us1[m] != us2[m])
			return (us1[m] - us2[m]);
		m++;
	}
	return (0);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char s1[] = "Hello";
//	char s2[] = "Hello";
//	char s3[] = "World";
//
//	printf("ft_memcmp(\"Hello\", \"Hello\", 5) = %d\n", ft_memcmp(s1, s2, 5));
//	printf("ft_memcmp(\"Hello\", \"World\", 5) = %d\n", ft_memcmp(s1, s3, 5));
//	printf("ft_memcmp(\"Hello\", \"Hello\", 3) = %d\n", ft_memcmp(s1, s2, 3));
//	printf("memcmp(\"Hello\", \"Hello\", 5) = %d\n", memcmp(s1, s2, 5));
//	printf("memcmp(\"Hello\", \"World\", 5) = %d\n", memcmp(s1, s3, 5));
//	printf("memcmp(\"Hello\", \"Hello\", 3) = %d\n", memcmp(s1, s2, 3));
//
//	return (0);
//}
