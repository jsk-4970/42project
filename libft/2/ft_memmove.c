/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:02:45 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/07 21:03:16 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*udest;
	unsigned char	*usrc;

    if (dest == NULL || src == NULL)
        return (dest);
	udest = (unsigned char *)dest;
	usrc = (unsigned char *)src;
	if (usrc >= udest)
		ft_memcpy(udest, usrc, n);
	else if (usrc < udest)
	{
		while (n--)
			udest[n] = usrc[n];
	}
	return (dest);
}

// void	*ft_memmove(void *dest, const void *src, size_t n)
//{
//	unsigned char	*tmpd;
//	unsigned char	*tmps;
//	unsigned char	tmp[n];
//	size_t			m;
//
//	m = 0;
//	tmpd = (unsigned char *)dest;
//	tmps = (unsigned char *)src;
//	while (m < n)
//	{
//		tmp[m] = tmps[m];
//		m++;
//	}
//	m = 0;
//	while (m < n)
//	{
//		tmpd[m] = tmp[m];
//		m++;
//	}
//	return (tmpd);
//}

//#include <stdio.h>
//#include <string.h>
//
// int main(void)
//{
//	char data[] = "ABCDEFGHIJ";
//	printf("Before: %s\n", data);
//	ft_memmove(data, "123", 5);
//	printf("After ft_memmove(data+2, data, 5): %s\n", data);
//
//	char data2[] = "ABCDEFGHIJ";
//	memmove(data2, data2 + 2, 5);
//	printf("After memmove(data2, data2+2, 5): %s\n", data2);
//	return (0);
//}
