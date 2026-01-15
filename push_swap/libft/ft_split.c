/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:28:14 by jyamada           #+#    #+#             */
/*   Updated: 2025/11/08 16:03:43 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char const *s, char c)
{
	int		count;
	int		in_words;

	if (s == NULL)
		return (0);
	count = 0;
	in_words = 0;
	while (*s)
	{
		if (*s == c)
			in_words = 0;
		else if (*s != c && in_words == 0)
		{
			count++;
			in_words = 1;
		}
		s++;
	}
	return (count);
}

int	ft_getlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

char	**ft_freeall(char **ret)
{
	int	y;

	y = 0;
	while (ret[y])
	{
		free(ret[y]);
		y++;
	}
	free(ret);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		n;
	int		i;
	int		len;

	n = ft_count(s, c);
	i = 0;
	ret = malloc((n + 1) * sizeof(char *));
	if (!ret || s == NULL)
		return (NULL);
	while (*s && i < n)
	{
		while (*s == c)
			s++;
		len = ft_getlen(s, c);
		ret[i] = ft_substr(s, 0, len);
		if (!ret[i])
			return (ft_freeall(ret));
		i++;
		s += len;
	}
	ret[i] = NULL;
	return (ret);
}

//#include <stdio.h>
// static void print_and_free_split(char **split_array)
//{
//    if (!split_array)
//    {
//        printf("Result -> NULL\n");
//        return ;
//    }
//    printf("Result -> {\n");
//    for (int i = 0; split_array[i] != NULL; i++)
//    {
//        printf("  [%d]: \"%s\"\n", i, split_array[i]);
//        free(split_array[i]);
//    }
//    printf("  [%s]: (null)\n", "last");
//    printf("}\n");
//    free(split_array);
//}
//
// int main(void)
//{
//    char **result;
//
//    printf("--- TEST 1: Basic case ---\n");
//    result = ft_split(" a b ", ' ');
//    print_and_free_split(result);
//    printf("\n");
//
//    printf("--- TEST 2: Multiple delimiters ---\n");
//    result = ft_split("see   you   later", ' ');
//    print_and_free_split(result);
//    printf("\n");
//
//    printf("--- TEST 3: Leading and trailing delimiters ---\n");
//    result = ft_split("  spaces everywhere  ", ' ');
//    print_and_free_split(result);
//    printf("\n");
//
//    printf("--- TEST 4: No delimiters ---\n");
//    result = ft_split("oneword", '-');
//    print_and_free_split(result);
//    printf("\n");
//
//    printf("--- TEST 5: String with only delimiters ---\n");
//    result = ft_split("xxxxxxxxhello", 'x');
//    print_and_free_split(result);
//    printf("\n");
//
//    printf("--- TEST 6: Empty string ---\n");
//    result = ft_split("", 'a');
//    print_and_free_split(result);
//    printf("\n");
//
//    printf("--- TEST 7: NULL string (Bonus) ---\n");
//    result = ft_split(NULL, 'z');
//    print_and_free_split(result);
//    printf("\n");
//
//    return (0);
//}
