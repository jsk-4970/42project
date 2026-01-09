/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:42:47 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/06 12:04:09 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// if c is in set return 0
int	ft_judgeset(char c, const char *set)
{
	char	*tmp;

	tmp = (char *)set;
	while (*tmp)
	{
		if (*tmp == c)
			return (0);
		tmp++;
	}
	return (1);
}

// return value is the pointer of the true start of s1
int	ft_setcheck_s(char const *s1, char const *set)
{
	int	start;

	if (!s1)
		return (0);
	start = 0;
	while (!ft_judgeset(s1[start], set) && s1[start])
		start++;
	return (start);
}

int	ft_setcheck_e(char const *s1, char const *set)
{
	int	end;

	if (!s1)
		return (0);
	end = ft_strlen(s1);
	while (end && !ft_judgeset(s1[end - 1], set))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		len;

	len = 0;
	if (!s1)
		return (NULL);
	while (s1[len] && !ft_judgeset(s1[len], set))
	{
		len++;
		if (len == (int)ft_strlen(s1))
			return (ft_strdup(""));
	}
	len = ft_setcheck_e(s1, set) - ft_setcheck_s(s1, set);
	if (len < 0)
		return (ft_strdup(""));
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1 + ft_setcheck_s(s1, set), len);
	ret[len] = '\0';
	return (ret);
}
//#include <stdio.h>
//int main(void)
//{
//	printf("s1 = *#*hello world**, set = #*, start = %d\n",
//		ft_setcheck_s("*#*hello world**", "#*"));
//	printf("s1 = *#*hello world**, set = #*, end = %d\n",
//		ft_setcheck_e("*#*hello world*#*", "#*"));
//	char *res = ft_strtrim("          ", " ");
//	printf("           , , res = %s\n", res);
//}
