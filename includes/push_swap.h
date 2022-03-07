/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:12:11 by vrogiste          #+#    #+#             */
/*   Updated: 2022/03/07 11:25:45 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

enum
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_list
{
	int				val;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_ps
{
	t_list	*a;
	t_list	*b;
	size_t	ops;
	bool	print;
	bool	prepare;
}	t_ps;

/*lst*/
t_list			*lst_new(int val);
int				lst_size(t_list *lst);
t_list			*lst_last(t_list *lst);
void			lst_add_front(t_list **alst, t_list *new_node);
void			lst_add_back(t_list **alst, t_list *new_node);

/*op*/
void			swap(t_list **head);
void			rotate(t_list **head);
void			reverse_rotate(t_list **head);
void			push(t_list **a_src, t_list **dst);

/*do_op*/
void			do_op(int op, t_ps *ps);

/*cost*/
int				dtt(t_list *node);
t_list			*find_min_cost(t_ps *ps);

/*sort*/
t_list			*homologue(t_list *node, t_list *b);
bool			is_sorted(t_list *head);
void			sort(t_ps *ps);

/*min_max*/
int				ft_abs(int n);
int				abs_min(int a, int b);
int				abs_max(int a, int b);
t_list			*lst_min(t_list *head);
t_list			*lst_max(t_list *head);

/*prepare*/
void			prepare(t_ps *ps);

/*sort_small*/
void			sort_small(t_ps *ps);

/*clear*/
void			ps_clear(t_ps *ps);

/*utils*/
size_t			ft_strlen(const char *str);
void			ft_putstr_fd(char *s, int fd);
bool			ft_str_isdigit(char *str);
int				ft_strcmp(char *s1, char *s2);
long long int	ft_atol(const char *str);

#endif
