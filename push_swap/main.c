/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:20:18 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/15 10:48:42 by jyamada          ###   ########.fr       */
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

char	*validate(char **av)
{
	char	*ret;


}

//function to make new_stack and fill it
t_stack	*make_new_stack(int value)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->value = value;
	return (new);
}

//function to find the last stack
t_stack	*find_last_stack(t_stack *list)
{
	if (list == NULL)
		return (list);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

//function to add node to the last list
//its gonna be complicate to free when something fail
void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last_list;

	if (*stack == NULL)
		*stack = new;
	else
	{
		last_list = find_last_stack(*stack);
		last_list->next = new;
	}
}

//function to make stack from argv
//if it fail to init, return -1
//success to init, return 1
int	init_stack_a(t_stack **a, char **argv)
{
	int		value;
	argv++;
	while (*argv)
	{
		if (is_valid_number(*argv))
			return (-1);
		value = ft_atol(*argv);
		stack_add_back(a, make_new_stack(value));
		argv++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*args;

	if (ac <= 1)
		return (0);
	if (ac == 2)
		args = split_and_validate(av[1]);
	else
		args = validate(av);
	if (!args)
		return (1, write(2, "Error\n", 6));
	init_stack_a(a, argv);
	
	push_swap(args);
	free_args(args);
	return (0);
}
