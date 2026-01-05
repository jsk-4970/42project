/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:20:18 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/05 14:45:35 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

//if str is not int, return 0
int		is_valid_int(char *str)
{
	int		len;
	int		is_minus;

	is_minus = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_minus == 1;
		str++;
	}
	if (!is_all_digits(str))
		return (0);
	while (*str == '0' && *(str + 1))
		str++;
	len = ft_strlen(str);
	if (len > 10)
		return (0);
	if (is_minus)
		return (ft_strncmp(str, "2147483648", len) <= 0);
	else
		return (ft_strncmp(str, "2147483648", len) <= 0);
	return (0);
}

char	*validate_args(char **av)
{
	char	*ret;


}

int	main(int ac, char **av)
{
	char	*args;

	if (ac <= 1)
		return (0);
	if (ac == 2)
		args = split_and_validate(av[1]);
	else
		args = 
	if (!args)
		return (1, write(2, "Error\n", 6));
	push_swap(args);
	free_args(args);
	return (0);
}
