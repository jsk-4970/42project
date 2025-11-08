/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:24:01 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/08 14:32:53 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			m;
	unsigned char	*us1;
	unsigned char	*us2;

	m = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (us1 != 0 && us2 == 0)
		return (1);
	while (m < n && (us1[m] || us2[m]))
	{
		if (us1[m] > us2[m])
			return (1);
		else if (us1[m] < us2[m])
			return (-1);
		m++;
	}
	return (0);
}

//#include <stdio.h>
//#include <string.h>
//
// int main(void)
//{
//	printf("ft_strncmp(\"Hello\", \"Hello\", 5) = %d\n",
//		ft_strncmp("Hello", "Hello", 5));
//	printf("ft_strncmp(\"Hello\", \"World\", 5) = %d\n",
//		ft_strncmp("Hello", "World", 5));
//	printf("ft_strncmp(\"Hello\", \"Hellooo\", 5) = %d\n",
//		ft_strncmp("Hello", "Hellooo", 5));
//	printf("ft_strncmp(\"Hello\", \"Hellooo\", 7) = %d\n",
//		ft_strncmp("Hello", "Hellooo", 7));
//	printf("ft_strncmp(\"abc\", \"abz\", 2) = %d\n",
//		ft_strncmp("abc", "abz", 2));
//	printf("strncmp(\"Hello\", \"Hello\", 5) = %d\n",
//		strncmp("Hello", "Hello", 5));
//	printf("strncmp(\"Hello\", \"World\", 5) = %d\n",
//		strncmp("Hello", "World", 5));
//	printf("strncmp(\"Hello\", \"Hellooo\", 5) = %d\n",
//		strncmp("Hello", "Hellooo", 5));
//	printf("strncmp(\"Hello\", \"Hellooo\", 7) = %d\n",
//		strncmp("Hello", "Hellooo", 7));
//	printf("strncmp(\"abc\", \"abz\", 2) = %d\n",
//		strncmp("abc", "abz", 2));
//
//	return (0);
//}
