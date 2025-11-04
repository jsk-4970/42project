/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:35:49 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/03 23:05:41 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_nlen(int n)
{
	int		ret;
	long	longn;

	longn = (long)n;
	ret = 0;
	if (longn < 0)
	{
		ret++;
		longn *= -1;
	}
	while (longn > 0)
	{
		longn /= 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	int		nlen;
	char	*ret;
	long	longn;

	if (n == 0)
		return (ft_strdup("0"));
	nlen = ft_nlen(n);
	longn = (long)n;
	ret = malloc(sizeof(char) * (nlen + 1));
	if (ret == NULL)
		return (NULL);
	if (longn < 0)
		longn *= -1;
	ret[nlen] = '\0';
	while (nlen > 0)
	{
		ret[nlen - 1] = longn % 10 + '0';
		longn /= 10;
		nlen--;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}

//#include <stdio.h>
//
//int main(void)
//{
//	int n = -13;
//	char *s = ft_itoa(n);
//	printf("res = %s\n", s);
//	free(s);
//}
