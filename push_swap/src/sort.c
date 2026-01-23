/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:36:34 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/23 13:38:13 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		re_rank(t_stack **a)
{
	int		i;
	int		ret;
	t_stack	*tmp;
	t_stack *current;

	ret = 0;
	current = *a;
	while (current)
	{
		i = 0;
		tmp = *a;
		while (tmp)
		{
			if (tmp->value < (current)->value)
				i++;
			tmp = tmp->next;
		}
		current->index = i;
		if (ret < i)
			ret = i;
		current = current->next;
	}
	return (ret);
}

void	separate(t_stack **a, t_stack **b, int bit, int size)
{
	while (*a && 0 < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		size--;
	}
}

void	kick_back(t_stack **a, t_stack **b)
{
	while (*b)
		pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	size;
	int	i;

	size = re_rank(a) + 1;
	i = 0;
	while (i < size)
	{
		separate(a, b, i, size);
		kick_back(a, b);
		i++;
	}
}
