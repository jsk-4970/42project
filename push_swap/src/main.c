/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:20:18 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/15 19:47:18 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//if str is not int, return 0
//int		is_valid_int(char *str)
//{
//	int		len;
//	int		is_minus;
//
//	is_minus = 0;
//	if (*str == '-' || *str == '+')
//	{
//		if (*str == '-')
//			is_minus = 1;
//		str++;
//	}
//	if (!is_all_digits(str))
//		return (0);
//	while (*str == '0' && *(str + 1))
//		str++;
//	len = ft_strlen(str);
//	if (len > 10)
//		return (0);
//	if (is_minus)
//		return (ft_strncmp(str, "2147483648", len) <= 0);
//	else
//		return (ft_strncmp(str, "2147483648", len) <= 0);
//	return (0);
//}
//
//char	*validate(char **av)
//{
//	char	*ret;
//
//
//}

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

//func to return 1 if (char *)num is "num"
int		is_valid_number(char *num)
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

//func to return 1, if all of the nodes are differnt
int	is_diff_num(t_stack *list)
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

//function to make stack from argv
//if it fail to init, return 0
//success to init, return 0
int	init_stack_a(t_stack **a, char **argv)
{
	long	value;
	while (*argv)
	{
		if (!is_valid_number(*argv))
			return (free_stack(*a), 0);
		value = ft_atol(*argv);
		if (value > INT_MAX || value < INT_MIN)
			return (free_stack(*a), 0);
		stack_add_back(a, make_new_stack((int)value));
		argv++;
	}
	if (!is_diff_num(*a))
		return (free_stack(*a), 0);
	return (1);
}

//as a validation, it has different ways using split or not 
//then to free collectlly it should make a flag whether using split
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
		return (1);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		flag_to_free = 1;
	}
	else
		args = av + 1;
	if (!args)
		return (write(2, "Error\n", 6), 1);
	if (!init_stack_a(&a, args))
		return (free_args(args, flag_to_free), 1);
	push_swap(a, b);
	free_args(args, flag_to_free);
	return (0);
}
