/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:46:06 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/25 16:03:46 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*us;
	size_t			i;

	us = (unsigned char *)s;
	i = 0;
	if (s == NULL)
		return ;
	while (i < n)
	{
		us[i] = 0;
		i++;
	}
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char buf[20] = "Hello, World!";
//	printf("Before: %s\n", buf);
//	ft_bzero(buf, 5);
//	printf("After ft_bzero(5): ");
//	for (int i = 0; i < 13; i++)
//		printf("%c", buf[i] == 0 ? '0' : buf[i]);
//	printf("\n");
//	return (0);
//}
