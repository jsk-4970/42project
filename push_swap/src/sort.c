/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:36:34 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/23 12:49:36 by jyamada          ###   ########.fr       */
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

void	separate(t_stack **a, t_stack **b, int i)
{
	while (*a && 0 < fini)
	{
		if (((*a)->index >> 1) & 1)
			pb(a, b);
		else
			ra(a);
		fini;
	}
}

void	kick_back(t_stack **a, t_stack **b)
{
	while (*b)
		pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	fini;
	int	i;

	fini = re_rank(a);
	i = 0;
	while (i < fini)
	{
		separate(a, b, i);
		kick_back(a, b);
		i++;
	}
}
