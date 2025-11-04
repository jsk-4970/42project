/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:29:53 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/28 09:25:24 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	n;
	int	len;

	if (str == NULL)
		return (0);
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
//	printf("ft_strlen(\"hello 42!\") = %d\n", ft_strlen("hello 42!"));
//	printf("ft_strlen(\"\") = %d\n", ft_strlen(""));
//	printf("ft_strlen(\"a\") = %d\n", ft_strlen("a"));
//	printf("ft_strlen(\"Hello, World!\") = %d\n", ft_strlen("Hello, World!"));
//	return (0);
//}
