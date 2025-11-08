/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:07:15 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/30 12:24:17 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*tmp;

	tmp = (char *)s;
	c %= 256;
	len = ft_strlen(s);
	if (c == 0)
		return (tmp + len);
	while (0 <= len)
	{
		if (tmp[len] == c)
			return (&tmp[len]);
		len--;
	}
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char str[] = "tokugawaieyasu";
//	char *result;
//
//	result = strrchr(str, 'a');
//	if (result)
//		printf("Last 'a' found at: %s\n", result);
//	else
//		printf("'a' not found\n");
//
//	result = strrchr(str, 'z');
//	if (result)
//		printf("Last 'z' found at: %s\n", result);
//	else
//		printf("'z' not found\n");
//	return (0);
//}
