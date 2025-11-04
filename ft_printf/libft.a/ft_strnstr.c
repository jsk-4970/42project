/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:45:21 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/31 22:54:54 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	int		m;
	int		llen;
	char	*tmp;

	n = 0;
	tmp = (char *)big;
	if (little == NULL || big == NULL || len == 0)
		return (NULL);
	if (!ft_strncmp(little, "", len))
		return (&tmp[n]);
	llen = ft_strlen(little);
	while (n < len && tmp[n])
	{
		m = 0;
		while (tmp[n + m] == little[m] && n + m < len)
		{
			if (m == llen - 1)
				return (&tmp[n]);
			m++;
		}
		n++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	haystack[] = "lorem ipsum dolor sit amet";
// 	char	*result;

// 	result = ft_strnstr(haystack, "", 30);
// 	if (result)
// 		printf("Found \"ipsumm\": %s\n", result);
// 	else
// 		printf("\"ipsumm\" not found\n");
// 	result = ft_strnstr(haystack, "llo", 10);
// 	if (result)
// 		printf("Found \"llo\" in first 10 chars: %s\n", result);
// 	else
// 		printf("\"llo\" not found in first 10 chars\n");
// 	return (0);
// }
