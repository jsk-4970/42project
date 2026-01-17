/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:36:34 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/17 20:52:27 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		re_rank(t_stack **a)
{
	int		i;
	int		ret;
	t_stack	tmp;

	ret = 0;
	while (!(*a)->next)
	{
		i = 0;
		tmp = *a;
		while (!tmp->next)
		{
			if (tmp->value < (*a)->value)
				i++;
			tmp = tmp->next;
		}
		(*a)->index = i;
		if (ret < i)
			ret = i;
		*a = (*a)->next;
	}
	return (ret);
}

void	separate(t_stack **a, t_stack **b)
{
	while (!(*a)->next)
	{
		if ((*a)->index % 2 == 0)
			pb(a, b);
		else
			ra(a);
		*a = (*a)->next;
	}
}

void	kick_back(t_stack **a, t_stack **b)
{
	while (!(*b)->next)
	{
		pa(a, b);
		*b = (*b)->next;
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	fini;
	int	i;

	fini = re_rank(a);
	i = 0;
	while (i < fini)
	{
		separate(a, b);
		kick_back(a, b);
		i++;
	}
}
