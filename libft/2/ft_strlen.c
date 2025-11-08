/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:29:53 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/08 12:19:47 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;
	size_t	len;

	n = 0;
	len = 0;
	while (str[n])
	{
		n++;
		len++;
	}
	return (len);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	printf("ft_strlen(\"hello 42!\") = %ld\n", ft_strlen("hello 42!"));
//	printf("ft_strlen(\"\") = %ld\n", ft_strlen(""));
//	printf("ft_strlen(\"a\") = %ld\n", ft_strlen("a"));
//	printf("ft_strlen(\"Hello, World!\") = %ld\n", ft_strlen("Hello, World!"));
//	printf("ft_strlen(\"\") = %ld\n", ft_strlen(""));
//	return (0);
//}
