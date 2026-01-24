/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:36:34 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/24 15:57:36 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

///Orders the number of value in a. 
///The return value is the number of values in a.
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

int		is_sorted(t_stack **a)
{
	while (*a != NULL)
	{
		if (!((*a)->value < (*a)->next->value))
			return (0);
		*a = (*a)->next;
	}
	return (1);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	size;
	int	max_rank;
	int	max_bits;
	int	i;

	max_rank = re_rank(a);
	if (is_sorted(a))
		return ;
	size = max_rank + 1;
	if (size <= 5)
		small_sort(a, b, size);
	max_bits = 0;
	while ((max_rank >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		separate(a, b, i, size);
		kick_back(a, b);
		i++;
	}
}
