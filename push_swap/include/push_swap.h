/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <aburi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:41:50 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/24 15:55:46 by aburi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*find_last_stack(t_stack *list);
t_stack	*make_new_stack(int value);
int		stack_add_back(t_stack **stack, t_stack *new);

void	push_swap(t_stack **a, t_stack **b);
int		re_rank(t_stack **a);

void	sa(t_stack **a);
void	sb(t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	small_sort(t_stack **a, t_stack **b, int num_a);
void	sort_3(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);

void	free_args(char **args, int flag_to_free);
void	free_stack(t_stack *a);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
long	ft_atol(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
