/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <aburi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:41:50 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/23 13:26:07 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

//# include "../libft/libft.h"
//# include "../printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* main.c */
t_stack	stack_new(int value);
int		is_valid_int(char *str);
char	*validate_args(char **av);
t_stack	*find_last_stack(t_stack *list);

/* parse.c */
int		is_all_digits(char *str);
char	*split_and_validate(char *str);

/* sort.c */
void	push_swap(t_stack **a, t_stack **b);
int		re_rank(t_stack **a);
void	separate(t_stack **a, t_stack **b, int bit, int size);
void	kick_back(t_stack **a, t_stack **b);

/* operation.c - swap */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/* operation.c - push */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/* operation.c - rotate */
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/* operation.c - reverse rotate */
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* utils.c */
void	error_exit(void);

void	free_args(char **args, int flag_to_free);
void	free_stack(t_stack *a);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
long	ft_atol(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

#endif
