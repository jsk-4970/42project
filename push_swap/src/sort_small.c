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

void	small_sort(t_stack **a, t_stack **b, int num_a)
{
	if (num_a == 3)
		sort_3(a, b);
	else if (num_a == 4 || num_a == 5)
		sort_5(a, b);
	
}

void	sort_3(t_stack **a, t_stack **b)
{
	if ((*a)->index == 1 && (*a)->next->index == 2)
	{
		rra(a);
		sa(a);
	}
	else if ((*a)->index == 2 && (*a)->next->index == 1)
		sa(a);
	else if ((*a)->index == 2 && (*a)->next->index == 3)
		rra(a);
	else if ((*a)->index == 3 && (*a)->next->index == 1)
		ra(a);
	else if ((*a)->index == 3 && (*a)->next->index == 2)
	{
		ra(a);
		sa(a);
	}
}

void	sort_5(t_stack **a, t_stack **b)
{

}
