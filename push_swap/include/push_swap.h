/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburi <aburi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:41:50 by jyamada           #+#    #+#             */
/*   Updated: 2026/01/09 18:22:58 by jyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				*value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* main.c */
t_stack	stack_new(int value);
int		is_valid_int(char *str);
char	*validate_args(char **av);

/* parse.c */
int		is_all_digits(char *str);
char	*split_and_validate(char *str);
void	free_args(char *args);

/* sort.c */
void	push_swap(char *args);

/* operation.c - swap */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

/* operation.c - push */
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

/* operation.c - rotate */
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

/* operation.c - reverse rotate */
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* utils.c */
void	error_exit(void);

int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
