/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:50:46 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/30 12:24:15 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	c %= 256;
	tmp = (char *)s;
	if (c == 0)
		return (tmp + ft_strlen(s));
	while (*tmp)
	{
		if (*tmp == c)
			return (tmp);
		tmp++;
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
//	result = ft_strchr(str, 'a');
//	if (result)
//		printf("Found 'a' at: %s\n", result);
//	else
//		printf("'a' not found\n");
//
//	result = ft_strchr(str, 'z');
//	if (result)
//		printf("Found 'z' at: %s\n", result);
//	else
//		printf("'z' not found\n");
//
//	return (0);
//}
