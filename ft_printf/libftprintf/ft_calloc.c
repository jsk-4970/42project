/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:14:31 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/29 21:57:42 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	char	*ret;
	size_t	i;

	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	ret = mem;
	i = 0;
	while (i < nmemb)
	{
		mem[i] = 0;
		i++;
	}
	return (ret);
}

//#include <stdio.h>
//
//int main(void)
//{
//	char	*c;
//	c = ft_calloc(1, 100);
//
//}
