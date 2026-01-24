/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:24:45 by aburi             #+#    #+#             */
/*   Updated: 2026/01/24 16:04:17 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

static int	get_min_pos(t_stack *stack)
{
	int		min_idx;
	int		min_pos;
	int		pos;
	t_stack	*tmp;

	min_idx = stack->index;
	min_pos = 0;
	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index < min_idx)
		{
			min_idx = tmp->index;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

void	sort_3(t_stack **a, t_stack **b)
{
	int	first;
	int	second;
	int	third;

	(void)b;
	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && first > third)
	{
		ra(a);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	else if (second > first && second > third)
	{
		rra(a);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	else if (first > second)
		sa(a);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	size;
	int	pos;

	while (stack_size(*a) > 3)
	{
		pos = get_min_pos(*a);
		size = stack_size(*a);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(a);
		}
		else
		{
			while (pos++ < size)
				rra(a);
		}
		pb(a, b);
	}
	sort_3(a, b);
	while (*b)
		pa(a, b);
}

void	small_sort(t_stack **a, t_stack **b, int num_a)
{
	if (num_a == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	else if (num_a == 3)
		sort_3(a, b);
	else if (num_a == 4 || num_a == 5)
		sort_5(a, b);
}
