/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyamada <jyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:50:22 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/17 13:01:54 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack **a)
{
	int	tmp;
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	int	tmp;
	if (b == NULL || *b == NULL || (*b) == NULL)
		return ;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	write(1, "sb\n", 3);
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!from || !*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
}
	
void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
