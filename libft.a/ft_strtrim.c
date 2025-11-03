/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:42:47 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/31 23:51:41 by jyamada          ###   ########.fr       */
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

	start = 0;
	while (!ft_judgeset(s1[start], set) && s1[start])
		start++;
	return (start);
}

int	ft_setcheck_e(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen(s1);
	while (!ft_judgeset(s1[end - 1], set) && end)
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		start;
	int		end;
	int		len;

	if (!s1)
		return (NULL);
	start = ft_setcheck_s(s1, set);
	end = ft_setcheck_e(s1, set);
	len = end - start;
	if (len < 0)
		return ("");
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1 + start, len);
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
//	char *res = ft_strtrim("**##$hello world*#*", "*#");
//	printf("s1 = *#*hello world**, set = **, res = %s\n", res);
//}
