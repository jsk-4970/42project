/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:45:12 by jyamada           #+#    #+#             */
/*   Updated: 2025/10/31 21:42:21 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*ret;
	int		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	ret = malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

// char add_one(unsigned int i, char c)
// {
//     // We don't use the index, so we can cast it to void
//     // to prevent compiler warnings.
//     (void)i;

//     return (c + 1);
// }

//#include <stdio.h>
// int main(void)
//{
//    char *str = "abc";
//    char *result;
//
//    printf("--- Test 1: Simple String ---\n");
//    printf("Original:     \"%s\"\n", str);
//    printf("Function:     add_one (e.g., 'a' -> 'b')\n");
//
//    // Call your function
//    result = ft_strmapi(str, &add_one);
//
//    if (result)
//    {
//        printf("Expected:     \"bcd\"\n");
//        printf("Got:          \"%s\"\n", result);
//
//        // Don't forget to free the new string!
//        free(result);
//    }
//    else
//    {
//        printf("Got:          NULL (Error!)\n");
//    }
//
//    printf("\n--- Test 2: NULL String ---\n");
//
//    // Call your function with NULL
//    result = ft_strmapi(NULL, &add_one);
//
//    if (result == NULL)
//    {
//        printf("Expected:     NULL\n");
//        printf("Got:          NULL (Correct!)\n");
//    }
//    else
//    {
//        printf("Expected:     NULL\n");
//        printf("Got:          \"%s\" (Error!)\n", result);
//        free(result);
//    }
//
//    return (0);
//}
//
