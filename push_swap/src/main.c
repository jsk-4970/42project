/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:20:18 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/29 00:00:00 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_valid_number(char *num)
{
	if (*num == '+' || *num == '-')
		num++;
	if (*num == 0)
		return (0);
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}

static int	is_diff_num(t_stack *list)
{
	int		n;
	t_stack	*current;
	t_stack	*check;

	if (list == NULL)
		return (1);
	current = list;
	while (current)
	{
		n = current->value;
		check = current->next;
		while (check)
		{
			if (n == check->value)
				return (0);
			check = check->next;
		}
		current = current->next;
	}
	return (1);
}

static int	init_stack_a(t_stack **a, char **args)
{
	long	value;

	while (*args)
	{
		if (!is_valid_number(*args))
			return (free_stack(*a), 0);
		value = ft_atol(*args);
		if (value > INT_MAX || value < INT_MIN)
			return (free_stack(*a), 0);
		if (stack_add_back(a, make_new_stack((int)value)) == 0)
			return (free_stack(*a), 0);
		args++;
	}
	if (!is_diff_num(*a))
		return (free_stack(*a), 0);
	return (1);
}

int	main(int ac, char **av)
{
	char	**args;
	t_stack	*a;
	t_stack	*b;
	int		flag_to_free;

	a = NULL;
	b = NULL;
	flag_to_free = 0;
	if (ac <= 1)
		return (write(2, "Error\n", 6), 1);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		flag_to_free = 1;
	}
	else
		args = av + 1;
	if (!args || !args[0])
		return (free_args(args, flag_to_free), write(2, "Error\n", 6), 1);
	if (!init_stack_a(&a, args))
		return (free_args(args, flag_to_free), write(2, "Error\n", 6), 1);
	push_swap(&a, &b);
	free_stack(a);
	free_args(args, flag_to_free);
	return (0);
}
