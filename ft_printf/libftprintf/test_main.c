#include <stdio.h>
#include "libftprintf.h"

int main(void)
{
    int ft_ret, std_ret;

    printf("=== Test 1: Basic string ===\n");
    printf("標準: ");
    std_ret = printf("hello\n");
    printf("ft  : ");
    ft_ret = ft_printf("hello\n");
    printf("標準の戻り値: %d, ft_printfの戻り値: %d\n\n", std_ret, ft_ret);

    printf("=== Test 2: Character ===\n");
    printf("標準: ");
    std_ret = printf("char: %c\n", 'A');
    printf("ft  : ");
    ft_ret = ft_printf("char: %c\n", 'A');
    printf("標準の戻り値: %d, ft_printfの戻り値: %d\n\n", std_ret, ft_ret);

    printf("=== Test 3: String with %%s ===\n");
    printf("標準: ");
    std_ret = printf("%s\n", "world");
    printf("ft  : ");
    ft_ret = ft_printf("%s\n", "world");
    printf("標準の戻り値: %d, ft_printfの戻り値: %d\n\n", std_ret, ft_ret);

    printf("=== Test 4: Integer ===\n");
    printf("標準: ");
    std_ret = printf("number: %d\n", 42);
    printf("ft  : ");
    ft_ret = ft_printf("number: %d\n", 42);
    printf("標準の戻り値: %d, ft_printfの戻り値: %d\n\n", std_ret, ft_ret);

    printf("=== Test 5: Multiple args ===\n");
    printf("標準: ");
    std_ret = printf("%s %d\n", "hello", 2);
    printf("ft  : ");
    ft_ret = ft_printf("%s %d\n", "hello", 2);
    printf("標準の戻り値: %d, ft_printfの戻り値: %d\n\n", std_ret, ft_ret);

    printf("=== Test 6: Zero ===\n");
    printf("標準: ");
    std_ret = printf("%d\n", 0);
    printf("ft  : ");
    ft_ret = ft_printf("%d\n", 0);
    printf("標準の戻り値: %d, ft_printfの戻り値: %d\n\n", std_ret, ft_ret);

    printf("=== Test 7: Negative ===\n");
    printf("標準: ");
    std_ret = printf("%d\n", -42);
    printf("ft  : ");
    ft_ret = ft_printf("%d\n", -42);
    printf("標準の戻り値: %d, ft_printfの戻り値: %d\n\n", std_ret, ft_ret);

    printf("=== Test 8: Percent ===\n");
    printf("標準: ");
    std_ret = printf("%%\n");
    printf("ft  : ");
    ft_ret = ft_printf("%%\n");
    printf("標準の戻り値: %d, ft_printfの戻り値: %d\n\n", std_ret, ft_ret);

    return (0);
}
